import os
import platform
import functools

path = {
    'Windows': 'C://Users//Vernon//AppData//Roaming//Code//User//snippets//{language}.json',
    'Linux': '/mnt/c/Users/Vernon/AppData/Roaming/Code/User/snippets/{language}.json',
    'Darwin': '/Users/vernon/Library/Application Support/Code/User/snippets/{language}.json'
}

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
            'cerr << \\"Elapsed time: \\" << elapsed.count() << endl;'
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
        'body': [
            'for(int ${1:i}${1:i} = ${2:mask}, ${1:i} = ctz(${1:i}${1:i}); ${1:i}${1:i} > 0; ${1:i}${1:i} &= ~(${1:i}${1:i} & -${1:i}${1:i}), ${1:i} = ctz(${1:i}${1:i})) {', 
                '\\t$3', 
            '}'
        ]
    }, {
        'name': 'Read Tree',
        'prefix': 'Read Tree',
        'body': [
            'int n;',
            'cin >> n;',
            'graph<${1:0}, ${2:edge}, ${3:1}> g(n, n - 1);',
            'for(int i = 0; i < n - 1; i++) {',
                '\\tint u, v;',
                '\\tcin >> u >> v;',
                '\\tg.add_edge({u, v});',
            '}'
        ]
    }, {
        'name': 'Read Graph',
        'prefix': 'Read Graph',
        'body': [
            'int n, m;',
            'cin >> n >> m;',
            'graph<${1:0}, ${2:edge}, ${3:1}> g(n, m);',
            'for(int i = 0; i < m; i++) {',
                '\\tint u, v;',
                '\\tcin >> u >> v;',
                '\\tg.add_edge({u, v});',
            '}'
        ]
    }, {
        'name': 'Read Weighted Graph',
        'prefix': 'Read Weighted Graph',
        'body': [
            'int n, m;',
            'cin >> n >> m;',
            'graph<${1:0}, ${2:wedge<ll>}, ${3:1}> g(n, m);',
            'for(int i = 0; i < m; i++) {',
                '\\tint u, v, w;',
                '\\tcin >> u >> v >> w;',
                '\\tg.add_edge({u, v, w});',
            '}'
        ]
    }],
    'python': [{
        'name': 'Read Ints',
        'prefix': 'Read Ints',
        'body': ['[int(x) for x in input().split()]']
    }, {
        'name': 'Multiple Test Cases',
        'prefix': 'Multiple Test Cases',
        'body': ['for ${1:_} in range(int(input())):']
    }, {
        'name': 'List of Zeros',
        'prefix': 'List of Zeros',
        'body': ['[0 for _ in range(${1:n})]']
    }]
}

def get_name(file_name):
    try:
        return file_name[file_name.index('-')+2:file_name.index('.')]
    except ValueError:
        return file_name[:file_name.index('.')]

ignored = ('#include', 'using namespace std', 'using ll', 'template <typename T> using lim', 'from', 'import')

@functools.lru_cache
def make_snippet(file_name, is_template=False):
    def gen():
        try:
            with open(file_name, encoding='utf-8', mode='r') as source:
                for line in source:
                    if is_template or not line.startswith(ignored):
                        yield line.rstrip().replace('"', '\\"')
                    elif line.startswith('#include "'):
                        included_file_name = line[line.index('"')+1:line.rindex('"')]
                        print(f'\tdependency: {included_file_name}')
                        yield from make_snippet(included_file_name)
        except FileNotFoundError:
            print('file not found')
    return list(gen())

def write_snippet(name, prefix, output_file, body=None, file_name=None):
    print(file_name or name)
    print(f'\t"{name}": {{ ', file=output_file)
    print(f'\t\t"prefix": "{prefix}",', file=output_file)
    print('\t\t"body": [', file=output_file)
    for line in body or make_snippet(file_name, name == 'Template'):
        print(f'\t\t\t"{line}",', file=output_file)
    print('\t\t]', file=output_file)
    print('\t},', file=output_file)

for language in ['cpp', 'python']:
    with open(path[platform.system()].format(language=language), encoding='utf-8', mode='w') as output_file:
        print('{', file=output_file)
        for file_name in [f for f in os.listdir('.') if valid[language](f)]:
            with open(file_name, encoding='utf-8', mode='r') as source:
                write_snippet(get_name(file_name), get_name(file_name), output_file, file_name=file_name)
        for snippet in extras.get(language, []):
            write_snippet(snippet['name'], snippet['prefix'], output_file, body=snippet['body'])
        print('}', file=output_file)
