#pragma once
#include "UI/Interface/IUIController.h"
#include "UI/UIElement/AnimatedImageView.h"

namespace UI
{
	namespace SplashScreen
	{
		class SplashScreenUIController : public Interface::IUIController
		{
		private:
			// Constants:
			const float logo_animation_duration = 2.0f;
			const float logo_width = 800.f;
			const float logo_height = 400.f;

			UIElement::AnimatedImageView* outscal_logo_view;

			void initializeOutscalLogo();
			void fadeInAnimationCallback();
			void fadeOutAnimationCallback();
			sf::Vector2f getLogoPosition();

		public:
			SplashScreenUIController();
			~SplashScreenUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}