#include "Spark.h"

namespace Spark {

	class SampleLayer : public Layer
	{
	public:
		SampleLayer(std::string name) : Layer(name) {   }

		void onEvent()
		{
			SP_LOG_INFO("Sample Layer Running!");
		}
	};

	class Sparkle : public Application
	{
	public:
		Sparkle()
		{
			SP_LOG_INFO("Sample Layer Created!")
			attachLayer(new SampleLayer("Sample Layer"));
			// attachLayer(new SampleLayer("Sample Layer"));
		}

		~Sparkle()
		{

		}
		
	};
	
}

Spark::Application* createApp()
{
	return new Spark::Sparkle();
}