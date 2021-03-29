from collections import namedtuple
wedge = namedtuple('wedge', ('u', 'v', 'w'))
wedge.__reversed__ = lambda self: wedge(self.v, self.u, self.w)
