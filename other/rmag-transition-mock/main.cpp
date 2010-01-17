/*
 * This is a mock up for RMAG
 * to test various transitions from
 * sane to insane. This is a mockup
 * so ignore the ugly code :P
 *
 * The only dependencie required to
 * build this is SFML
 *
 * Red-ish background is insanity
 * Blue-ish background is sanity
 *
 * //// CONTROLS ////
 * Currently only the whole screen fade
 * press SPACE to take the pill and run
 * through the effect.
 *
 * ~rcapote
 *
 */
// How long the pill lasts in seconds as float
#define PILL_EFFECT_LENGTH 5.0


#include <iostream>
#include <SFML/Graphics.hpp>


/*
 * This transition simply fades from
 * a black background into either
 * states. 
 */
class FadeTransition 
{
public:
	FadeTransition(sf::Image &bg)
	{
		m_transition.SetX(0);
		m_transition.SetY(0);
		m_transition.SetImage(bg);
		m_transition.SetColor(sf::Color(0, 0, 0, 255));
		m_animTimer = new sf::Clock();
		m_pillTimer = new sf::Clock();
		m_transitioning = DONE;
	}
	
	~FadeTransition()
	{
		delete m_animTimer;
	}
	
	enum  
	{
		NONE = 0,
		TO_INSANITY = 1,
		FROM_INSANITY = 2,
		DONE = 3
	};
	
	void takePill() {
		m_pillTimer->Reset();
		m_animTimer->Reset();
		m_transitioning = FROM_INSANITY;
		m_alpha = 255;
	}
	
	void tick(sf::RenderWindow* window)
	{
		if(m_transitioning == DONE)
		{
			return;
		}
		
		// Pill lasts for 15 seconds
		if (m_pillTimer->GetElapsedTime() >= PILL_EFFECT_LENGTH && m_transitioning != TO_INSANITY)
		{
			m_transitioning = TO_INSANITY;
			m_alpha = 255;
			m_animTimer->Reset();
		}
		
		// First we tick if we are transitioning
		// Then do some fade effects if the pill is 
		// about to wear out
		if (m_transitioning == TO_INSANITY)
		{
			fadeTick(0.0, 0.25);
			
			if (m_alpha <= 0)
			{
				m_transitioning = DONE;
			}
		}
		else if (m_transitioning == FROM_INSANITY)
		{
			fadeTick(0.0, 10);
		}

		
		window->Draw(m_transition);
	}
	
	int getTransitionState()
	{
		return m_transitioning;
	}
	
private:
	sf::Sprite m_transition;
	sf::Clock* m_animTimer;
	sf::Clock* m_pillTimer;
	int m_transitioning;
	float m_alpha;
	
	// ag is the alpha goal between 1 and 0
	void fadeTick(float ag, float speed) 
	{
		float alphaGoal = 255 * ag;
		
		m_alpha -= speed * m_animTimer->GetElapsedTime();
		
		if (m_alpha <= alphaGoal) 
		{
			m_transitioning = NONE;
			return;
		}
		
		m_transition.SetColor(sf::Color(0, 0, 0, m_alpha));
		
	}
};


/*
 * Don't ask me why I created a class
 * for this. Just how I'm used to doing 
 * things 
 */
class RMAGMock 
{
public:
	
	RMAGMock()
	{
		m_app = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "RMAG Transition Mock");
	}
	
	~RMAGMock()
	{
		delete m_app;
	}
	
	void Go()
	{
		sf::Color saneBgColor(100, 100, 150, 255); 
		sf::Color insaneBgColor(150, 100, 100, 255);
		
		sf::Image backgroundImage(800, 600, sf::Color(255, 255, 255, 255));
		sf::Image alienImage;
		if (!alienImage.LoadFromFile("alien.png"))
		{
			std::cout << "Failed to load alien.png" << std::endl;
			return;
		}
		
		sf::Sprite saneBackground;
		saneBackground.SetX(0);
		saneBackground.SetY(0);
		saneBackground.SetImage(backgroundImage);
		saneBackground.SetColor(saneBgColor);
		
		sf::Sprite insaneBackground;
		insaneBackground.SetX(0);
		insaneBackground.SetY(0);
		insaneBackground.SetImage(backgroundImage);
		insaneBackground.SetColor(insaneBgColor);
		
		FadeTransition fadeTran(backgroundImage);
		
		sf::Sprite alien;
		alien.SetX(400);
		alien.SetY(400);
		alien.SetScale(0.15, 0.15);
		alien.SetImage(alienImage);
		
		sf::Clock *animTimer = new sf::Clock();
		sf::Clock *pillTimer = new sf::Clock();
		
		bool insane = true;
		bool transitioning = false;
		int transFlag = 1; // 1 == to sanity 2 == from sanity
	    float alpha = 255.0;
									  
		while (m_app->IsOpened())
		{
			sf::Event event;
			while (m_app->GetEvent(event)) 
			{
				if (event.Type == sf::Event::Closed) 
					m_app->Close();
				
				
				if (event.Type == sf::Event::KeyPressed 
						&& event.Key.Code == sf::Key::Escape) 
					m_app->Close();
				
				if (event.Type == sf::Event::KeyPressed 
						&& event.Key.Code == sf::Key::Space)
				{
					fadeTran.takePill();
				}
				
			}
			
			m_app->Clear();
			
			// What a beautiful mess :P
			if (fadeTran.getTransitionState() == FadeTransition::TO_INSANITY ||
				fadeTran.getTransitionState() == FadeTransition::DONE)
				m_app->Draw(insaneBackground);
			else
				m_app->Draw(saneBackground);
			
			fadeTran.tick(m_app);
			
			m_app->Draw(alien);
			
			m_app->Display();
		}
		
		delete animTimer;
		delete pillTimer;
	}
	
private:
	sf::RenderWindow *m_app;
	
};



int main(int argc, char** argv)
{
	RMAGMock game;
	
	game.Go();
	
	return EXIT_SUCCESS;
}
	