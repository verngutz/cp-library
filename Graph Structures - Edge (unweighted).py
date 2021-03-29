from collections import namedtuple
edge = namedtuple('edge', ('u', 'v'))
edge.__reversed__ = lambda self: edge(self.v, self.u)
