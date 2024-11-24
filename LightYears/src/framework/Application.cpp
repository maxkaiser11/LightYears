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
				Tick(targetDeltaTime);
				Render();
			}
		}
	}
	void Application::Tick(float deltaTime)
	{
		std::cout << "Ticking at FrameRate: " << 1.f / deltaTime << std::endl;
	}
	void Application::Render()
	{
	}
}