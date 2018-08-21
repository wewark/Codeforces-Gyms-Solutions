import os

for gym in os.listdir('Solutions'):
    for problem in os.listdir('Solutions/%s' % gym):
        contents = ''
        with open('Solutions/%s/%s' % (gym, problem), 'r') as f:
            contents = f.read()
            header = "// %(gym_name)s\n// %(gym_num)s%(problem_letter)s\n\n" % {
                'gym_name': gym,
                'gym_num': gym[:6],
                'problem_letter': problem[0]
            }
            contents = header + contents

        with open('Solutions/%s/%s' % (gym, problem), 'w') as f:
            f.write(contents)
