import bacon

# ALL you're allowed to do here is register prototypes.
# this code runs in editor context as well as your game!

# TODO: whatever you do, to register prototypes...

class CoinPrototype(object):
	img = "data/images/coin.png"

bacon.Entity.Register(CoinPrototype)

	# if you don't set bounds explicitly, it uses the bounds from `img` ?
	# yes it should figure out those, I don't see a problem there