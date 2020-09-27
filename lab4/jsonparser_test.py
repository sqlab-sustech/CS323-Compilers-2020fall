import pathlib
import subprocess


DATA = pathlib.Path('data')


def jsonparser_output(json_file):
    out = subprocess.check_output(['./jp.out', json_file])
    return out.decode().strip()


def check_jsonchecker_fail_withlexical():
    data = DATA/'jsonchecker'
    for failjson in data.glob('fail*.json'):
        out = jsonparser_output(failjson)
        if ('lexical error' not in out) or ('_EXCLUDE' in failjson.name):
            continue
        print(f'For file {failjson.name}:')
        print(out)
        print('-'*80)


def check_jsonchecker_fail_syntaxonly():
    data = DATA/'jsonchecker'
    for failjson in data.glob('fail*.json'):
        out = jsonparser_output(failjson)
        if ('lexical error' in out) or ('_EXCLUDE' in failjson.name):
            continue
        print(f'For file {failjson.name}:')
        print(out)
        print('-'*80)



# check_jsonchecker_fail_withlexical()
check_jsonchecker_fail_syntaxonly()
