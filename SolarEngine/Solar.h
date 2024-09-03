#pragma once

#include "Core/Application.h"

#include "Core/Input.h"

#include "Core/Layer/Layer.h"

#include "Core/Logger/Logger.h"

#include "Core/Event/Event.h"
#include "Core/Event/ApplicationEvent.h"
#include "Core/Event/KeyboardEvent.h"
#include "Core/Event/MouseEvent.h"

#include "Core/Renderer/Renderer.h"
#include "Core/Renderer/Buffer.h"
#include "Core/Renderer/Texture.h"

#include "Core/TimeSteps.h"


//_______Entry Point_______
#include "EntryPoint.h"
//_________________________

#define Input Solar::Application::GetInstance()->GetInputState()