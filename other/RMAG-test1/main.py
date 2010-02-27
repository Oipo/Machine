import miniengine
import random

#engine = miniengine.Engine()
#engine.init()

miniengine.initengine()
while(true):
	miniengine.submitevent(random.randint(1,20))
