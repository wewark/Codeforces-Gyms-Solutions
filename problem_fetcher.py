import getpass
import hashlib
import os
import time
import string

import requests
from lxml import html

session_requests = requests.session()


def scrape_payload(page_name, url, new_payload):
    print('Loading ' + page_name + '...')
    result = session_requests.get(url)
    tree = html.fromstring(result.text)
    elements = list(set(tree.xpath("//input")))
    payload = {}
    for element in elements:
        payload[element.name] = element.get('value')
    for element in elements:
        for key, value in new_payload.items():
            if element.name == key:
                payload[element.name] = value
    return payload


def submit_form(url, payload, page_name):
    payload = scrape_payload(page_name, url, payload)
    result = session_requests.post(
        url,
        data=payload,
        headers=dict(referer=url))
    return result


def login_to_CF(username, password):
    login_page = 'http://codeforces.com/enter'
    payload = {
        'handleOrEmail': username,
        'password': password
    }
    submit_form(login_page, payload, 'Login Page')


def get_gym_name(gym_id):
    url = 'http://codeforces.com/gym/{}'.format(gym_id)
    result = session_requests.get(url)
    tree = html.fromstring(result.text)

    gym_name = tree.xpath('//*[@id="sidebar"]/div/table/tbody/tr/th/a/text()')
    return gym_name[0]


def get_AC_problems(gym_id):
    url = 'http://codeforces.com/gym/{}/my'.format(gym_id)
    result = session_requests.get(url)
    tree = html.fromstring(result.text)

    AC_problem_id = tree.xpath(
        '//*[@class="datatable"]/div[6]/table/tr/td[6]/span[@submissionverdict="OK"]/../../td[1]/span/text()')
    AC_problem_id += tree.xpath(
        '//*[@class="datatable"]/div[6]/table/tr/td[6]/span[@submissionverdict="OK"]/../../td[1]/a/text()')
    AC_problem_letter = tree.xpath(
        '//*[@class="datatable"]/div[6]/table/tr/td[6]/span[@submissionverdict="OK"]/../../td[4]/a/text()')
    AC_problem_letter = [i.strip()[0] for i in AC_problem_letter]

    problems = {}
    for i in range(len(AC_problem_id)):
        if AC_problem_letter[i] not in problems:
            problems[AC_problem_letter[i]] = AC_problem_id[i]

    return problems


def get_code(gym_id, problem_id):
    url = 'http://codeforces.com/gym/{}/submission/{}'.format(
        gym_id, problem_id)
    result = session_requests.get(url)
    tree = html.fromstring(result.text)

    code = tree.xpath('//*[@id="pageContent"]/div[3]/pre/text()')
    if len(code) == 0:
        print("Error: Code can't be fetched")
    code[0] = code[0].replace('\r\n', '\n')
    time.sleep(0.5)
    return code[0]


username = 'wewark'
password = getpass.getpass('Password: ')
login_to_CF(username, password)

gym_id = input('Gym ID: ')
print('Getting gym name...')
gym_name = get_gym_name(gym_id)
print(gym_name)
print('Getting problems...')
problems = get_AC_problems(gym_id)

valid_chars = "-_.() %s%s" % (string.ascii_letters, string.digits)
gym_name = ''.join(c for c in gym_name if c in valid_chars)
gym_dir = 'Solutions/{} - {}'.format(gym_id, gym_name)
if not os.path.exists(gym_dir):
    os.makedirs(gym_dir)

for letter, problem in problems.items():
    print('Writing problem {} code...'.format(letter))
    with open('{}/{}.cpp'.format(gym_dir, letter), 'w', encoding='utf-8') as f:

		# TODO: Check if the start byte is invalid and remove it
        contents = get_code(gym_id, problem)
        header = "// %(gym_name)s\n// %(gym_num)s%(problem_letter)s\n\n" % {
            'gym_name': gym_name,
            'gym_num': gym_id[:6],
            'problem_letter': letter[0]
        }
        contents = header + contents

        f.write(contents)
