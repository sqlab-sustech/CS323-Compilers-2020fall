import pathlib
import re
import subprocess


DATA = pathlib.Path('data')


def jsonparser_output(json_file):
    out = subprocess.check_output(['./jc.out', json_file])
    return int(out.decode().strip())


def check_jsonchecker_correct():
    for datafile in ['citm_catalog', 'twitter']:
        jsonfile = DATA/f'{datafile}.json'
        out = jsonparser_output(jsonfile)
        print(f'For {jsonfile.name}: ', end='')
        assert out == 1
        print('CORRECT')
        print('-'*80)
    else:
        print('All success!')


def check_jsonchecker_error():
    pass


check_jsonchecker_correct()
