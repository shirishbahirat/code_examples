A = ['spain','italy','germany','brazil','france','argentina','peru','bolivia','giappone']
B = [0,0,1,1,1,0,1,1,0]
out=[x for x,y in zip(A,B) if y is 0]
