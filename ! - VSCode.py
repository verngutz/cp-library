import os

valid = {
    'cpp': lambda f: os.path.isfile(f) and f.endswith('.cpp') and f[0] not in ('[', '_', '!'),
    'python': lambda f: os.path.isfile(f) and f.endswith('.py') and f[0] not in ('[', '_', '!')
}

extras = {
    'cpp': [{
        'name': 'pi',
        'prefix': 'pi',
        'body': ['constexpr double pi = acos(-1);']
    }, {
        'name': 'Benchmark',
        'prefix': 'Benchmark',
        'body': [
            'auto begin_t = chrono::high_resolution_clock::now();',
            'auto end_t = chrono::high_resolution_clock::now();',
            'chrono::duration<double> elapsed = end_t - begin_t;',
            'cerr << "Elapsed time: " << elapsed.count() << endl;'
        ]
    }, {
        'name': 'Memo Reset',
        'prefix': 'Memo Reset',
        'body': ['memset(mem, -1, sizeof mem);']
    }, {
        'name': 'For Loop',
        'prefix': 'for',
        'body': ['for(int ${1:i} = ${2:0}; ${1:i} <$3 ${4:n}; ${1:i}++) {', '\\t$5', '}']
    }, {
        'name': 'For Loop (Double)',
        'prefix': 'ford',
        'body': [
            'for(int ${1:i} = ${2:0}; ${1:i} <$3 ${4:n}; ${1:i}++) {',
                '\\tfor(int ${5:j} = ${6:0}; ${5:j} <$7 ${8:m}; ${5:j}++) {',
                    '\\t\\t$9',
                '\\t}',
            '}'
        ]
    }, {
        'name': 'Foreach Bit',
        'prefix': 'Foreach Bit',
        'body': ['for(int ${1:i}${1:i} = ${2:mask}, ${1:i} = ctz(${1:i}${1:i}); ${1:i}${1:i} > 0; ${1:i}${1:i} &= ~(${1:i}${1:i} & -${1:i}${1:i}), ${1:i} = ctz(${1:i}${1:i})) {', '\\t$3', '}']
    }]
}

def get_name(file_name):
    try:
        return file_name[file_name.index('-')+2:file_name.index('.')]
    except ValueError:
        return file_name[:file_name.index('.')]

def make_snippet(name, prefix, body, file):
    print(f'\t"{name}": {{ ', file=file)
    print(f'\t\t"prefix": "{prefix}",', file=file)
    print('\t\t"body": [', file=file)
    for line in body:
        if (name == 'Template'
            or not line.startswith(('#include <', 'using namespace', 'using ll', 'template <typename T> using lim', 'from', 'import'))
            or line.startswith(('#include <ext', 'using namespace __gnu'))):
            line = line.rstrip().replace('"', '\\"')
            print(f'\t\t\t"{line}",', file=file)
    print('\t\t]', file=file)
    print('\t},', file=file)

for language in ['cpp', 'python']:
    with open(f'C://Users//Vernon//AppData//Roaming//Code//User//snippets//{language}.json', encoding='utf-8', mode='w') as f:
        print('{', file=f)
        for file_name in [f for f in os.listdir('.') if valid[language](f)]:
            with open(file_name, encoding='utf-8', mode='r') as source:
                make_snippet(get_name(file_name), get_name(file_name), source, f)
        for snippet in extras.get(language, []):
            make_snippet(snippet['name'], snippet['prefix'], snippet['body'], f)
        print('}', file=f)
