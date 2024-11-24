#include <iostream>
#include "framework/Application.h"

namespace ly
{
	Application::Application()
		: m_Window{ sf::VideoMode(1024, 1024), "Light Years" },
		m_TargetFrameRate{60.f},
		m_TickClock{}
	{
		
	}


	void Application::Run()
	{
		m_TickClock.restart();
		float accumulatedTime = 0.f;
		float targetDeltaTime = 1.f / m_TargetFrameRate;
		while (m_Window.isOpen())
		{
			sf::Event windowEvent;
			while (m_Window.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					m_Window.close();
				}
			}

			accumulatedTime += m_TickClock.restart().asSeconds();
			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;
				TickInternal(targetDeltaTime);
				RenderInternal();
			}
		}
	}
	void Application::TickInternal(float deltaTime)
	{
		Tick(deltaTime);
	}
	void Application::RenderInternal()
	{
		m_Window.clear();

		Render();

		m_Window.display();
	}


	void Application::Render()
	{
		sf::RectangleShape rect{ sf::Vector2f{100, 100} };
		rect.setFillColor(sf::Color::Green);
		rect.setOrigin(50, 50);
		rect.setPosition(m_Window.getSize().x / 2.f, m_Window.getSize().y / 2.f);
		m_Window.draw(rect);
	}
	void Application::Tick(float deltaTime)
	{
	}
}