def keep_generated(generator, generated_set, unordered_ground_set=False):
    for i in generator:
        yield i
        generated_set.add(frozenset(i) if unordered_ground_set else i)
