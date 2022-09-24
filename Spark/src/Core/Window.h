#pragma once

#include "sppch.h"

#include "Core/Basics.h"
#include "Event/Event.h"

#include "GLFW/glfw3.h"

namespace Spark {

	struct WindowProp
	{
	public:
		std::string name;
		unsigned int height;
		unsigned int width;

		WindowProp(const std::string Name = "Spark Engine",
			unsigned int Width = 1280, unsigned int Height = 720)
			: name(Name), height(Height), width(Width) {  }
	};

	class SPARK_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual unsigned int getHeight() const = 0;
		virtual unsigned int getWidth() const = 0;

		// Window attributes
		virtual void setCallbackFunc(const EventCallbackFn& func) = 0;
		virtual void setVSync(bool Enabled) = 0;
		virtual bool isVSync() const = 0;

		static Window* createWindow(const WindowProp& props = WindowProp());

	};

}