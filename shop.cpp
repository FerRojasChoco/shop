#include<iostream> 
#include<SFML\Window.hpp>
#include<SFML\Graphics.hpp>


static sf::Text textConfig(const std::string& stringForText, sf::Vector2f position, int size, sf::Font& font)
{
	sf::Text txt;			//Declares and defines the text variable and then loads the corresponding data

	txt.setString(stringForText);
	txt.setPosition(position);
	txt.setCharacterSize(size);
	txt.setFont(font);
	txt.setFillColor(sf::Color::White);
	sf::FloatRect textRect = txt.getLocalBounds();  
	txt.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f); 

	return txt;
}

static const float VIEW_HEIGTH = 800.0f;

static void resizeView(sf::RenderWindow& w, sf::View& v)
{
	float aspectRatio = float(w.getSize().x) / float(w.getSize().y);
	v.setSize(VIEW_HEIGTH * aspectRatio, VIEW_HEIGTH);
}

int main()
{

	sf::RenderWindow w(sf::VideoMode(800.f, 800.f), "Shop");	//Window creation
	w.setFramerateLimit(60);
	sf::Vector2u windowSize= w.getSize(); 

	 
	sf::View backgrounView(sf::Vector2f(960.0f, 540.0f), sf::Vector2f(VIEW_HEIGTH, VIEW_HEIGTH)); 
	sf::View textView(sf::Vector2f(400.0f, 400.0f), sf::Vector2f(VIEW_HEIGTH, VIEW_HEIGTH)); 


	sf::Texture backgroundTexture;							
	backgroundTexture.loadFromFile("shopBackground.jpg");
	backgroundTexture.setSmooth(1);  
	sf::Vector2u backgroundTextureSize = backgroundTexture.getSize(); 
	
	sf::Sprite background;
	background.setTexture(backgroundTexture);
	


	sf::Font font;							//Declares a font variable and loads the specified font
	font.loadFromFile("Retro_Gaming.ttf");

	sf::Text texts[7];
	texts[0] = textConfig("WELCOME TO THE SHOP", sf::Vector2f(400.f, 100.f), 32, font);
	texts[1] = textConfig("Variant 1", sf::Vector2f(float(windowSize.x / 6), 200.f), 24, font);
	texts[2] = textConfig("Variant 2", sf::Vector2f(float((windowSize.x / 2)), 200.f), 24, font); 
	texts[3] = textConfig("Variant 3", sf::Vector2f(float(windowSize.x * (5.f/6.f)), 200.f), 24, font); 

	texts[4] = textConfig("BUY", sf::Vector2f(float(windowSize.x / 6), 400.f), 24, font);
	texts[5] = textConfig("BUY", sf::Vector2f(float((windowSize.x / 2)), 400.f), 24, font);
	texts[6] = textConfig("BUY", sf::Vector2f(float(windowSize.x * (5.f / 6.f)), 400.f), 24, font);

	bool run = true;
	while (run)
	{
		sf::Event e; 
		while (w.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
				run = false;
				break;
			case sf::Event::Resized:
				resizeView(w, backgrounView);
				resizeView(w, textView);
				break;
			}
		}


		backgrounView.move(0.5f, 0.2f);
	
		w.clear();		//views come after clear
		w.setView(backgrounView);
		w.draw(background); 

		w.setView(textView);
		for (int i = 0; i <= 6; i++)
			w.draw(texts[i]);

		w.display();
	}

}