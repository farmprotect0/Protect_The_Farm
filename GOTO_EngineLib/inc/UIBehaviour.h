#pragma once
#include "ScriptBehaviour.h"

namespace GOTOEngine
{
    class Canvas;
    class RectTransform;

    class UIBehaviour : public ScriptBehaviour
    {
    protected:
        UIBehaviour()
        {
            REGISTER_BEHAVIOUR_MESSAGE(Awake);
			REGISTER_BEHAVIOUR_MESSAGE(OnEnable);
			REGISTER_BEHAVIOUR_MESSAGE(OnDisable);
			REGISTER_BEHAVIOUR_MESSAGE(OnRectTransformDimensionsChange);
			REGISTER_BEHAVIOUR_MESSAGE(OnCanvasHierarchyChanged);
        }
        ~UIBehaviour() {};

        // UI 전용 라이프사이클
        virtual void Awake() {};
        virtual void OnEnable() {};
        virtual void OnDisable() {};
        virtual void OnRectTransformDimensionsChange() {}
        virtual void OnCanvasHierarchyChanged() {}
    };
}
