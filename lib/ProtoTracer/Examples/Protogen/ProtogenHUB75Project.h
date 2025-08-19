#pragma once

#include "../Templates/ProtogenProjectTemplate.h"
#include "../../Assets/Models/OBJ/DeltaDisplayBackground.h"
#include "../../Assets/Models/FBX/NukudeFlat.h"
#include "../../Assets/Models/FBX/BetaFront.h"
#include "../../Assets/Textures/Animated/Gamecube.h"

#include "../../Camera/CameraManager/Implementations/HUB75DeltaCameras.h"
#include "../../Controller/HUB75Controller.h"

class ProtogenHUB75Project : public ProtogenProject {
private:
    HUB75DeltaCameraManager cameras;
    HUB75Controller controller = HUB75Controller(&cameras, 50, 50);
    NukudeFace pM;
    BetaFront tM;
    
    DeltaDisplayBackground deltaDisplayBackground;
    GamecubeSequence gamecube = GamecubeSequence(Vector2D(192.0f, 192.0f), Vector2D(96.0f, 48.0f), 18.0f);

    
	const __FlashStringHelper* faceArray[11] = {F("DEFAULT"), F("ANGRY"), F("DOUBT"), F("FROWN"), F("LOOKUP"), F("SAD"), F("AUDIO1"), F("AUDIO2"), F("AUDIO3"), F("owo"), F("eye")};

    void LinkControlParameters() override {//Called from parent
        AddParameter(NukudeFace::Anger, pM.GetMorphWeightReference(NukudeFace::Anger), 15);
        AddParameter(NukudeFace::Sadness, pM.GetMorphWeightReference(NukudeFace::Sadness), 15, IEasyEaseAnimator::InterpolationMethod::Cosine);
        AddParameter(NukudeFace::Surprised, pM.GetMorphWeightReference(NukudeFace::Surprised), 15);
        AddParameter(NukudeFace::Doubt, pM.GetMorphWeightReference(NukudeFace::Doubt), 15);
        AddParameter(NukudeFace::Frown, pM.GetMorphWeightReference(NukudeFace::Frown), 15);
        AddParameter(NukudeFace::LookUp, pM.GetMorphWeightReference(NukudeFace::LookUp), 15);
        AddParameter(NukudeFace::LookDown, pM.GetMorphWeightReference(NukudeFace::LookDown), 15);

        AddParameter(NukudeFace::HideBlush, pM.GetMorphWeightReference(NukudeFace::HideBlush), 15, IEasyEaseAnimator::InterpolationMethod::Cosine, true);

        // AddViseme(Viseme::MouthShape::EE, pM.GetMorphWeightReference(NukudeFace::vrc_v_ee));
        // AddViseme(Viseme::MouthShape::AH, pM.GetMorphWeightReference(NukudeFace::vrc_v_aa));
        // AddViseme(Viseme::MouthShape::UH, pM.GetMorphWeightReference(NukudeFace::vrc_v_dd));
        // AddViseme(Viseme::MouthShape::AR, pM.GetMorphWeightReference(NukudeFace::vrc_v_rr));
        // AddViseme(Viseme::MouthShape::ER, pM.GetMorphWeightReference(NukudeFace::vrc_v_ch));
        // AddViseme(Viseme::MouthShape::OO, pM.GetMorphWeightReference(NukudeFace::vrc_v_oh));
        // AddViseme(Viseme::MouthShape::SS, pM.GetMorphWeightReference(NukudeFace::vrc_v_ss));

        AddBlinkParameter(pM.GetMorphWeightReference(NukudeFace::Blink));

        AddParameter(BetaFront::BlushEye, tM.GetMorphWeightReference(BetaFront::BlushEye), 40);
        AddParameter(BetaFront::HideBlush, tM.GetMorphWeightReference(BetaFront::HideBlush), 10, IEasyEaseAnimator::InterpolationMethod::Cosine, true);
        AddParameter(BetaFront::HideEyeBrow, tM.GetMorphWeightReference(BetaFront::HideEyeBrow), 10, IEasyEaseAnimator::InterpolationMethod::Cosine);
        AddParameter(BetaFront::HideSecondEye, tM.GetMorphWeightReference(BetaFront::HideSecondEye), 10, IEasyEaseAnimator::InterpolationMethod::Cosine);
        AddParameter(BetaFront::OwOMouth, tM.GetMorphWeightReference(BetaFront::OwOMouth), 60);
        AddParameter(BetaFront::SadEye, tM.GetMorphWeightReference(BetaFront::SadEye), 70, IEasyEaseAnimator::InterpolationMethod::Cosine);
        AddParameter(BetaFront::SadEyeBrow, tM.GetMorphWeightReference(BetaFront::SadEyeBrow), 80, IEasyEaseAnimator::InterpolationMethod::Cosine);
        AddParameter(BetaFront::SadMouth, tM.GetMorphWeightReference(BetaFront::SadMouth), 90, IEasyEaseAnimator::InterpolationMethod::Cosine);
        AddParameter(BetaFront::FlatMouth, tM.GetMorphWeightReference(BetaFront::FlatMouth), 50);
        AddParameter(BetaFront::DeadEye, tM.GetMorphWeightReference(BetaFront::DeadEye), 1);
        AddParameter(BetaFront::HeartEye, tM.GetMorphWeightReference(BetaFront::HeartEye), 30);
        AddParameter(BetaFront::AlphaGenCircle,tM.GetMorphWeightReference(BetaFront::AlphaGenCircle),  90, IEasyEaseAnimator::InterpolationMethod::Cosine);
        AddParameter(BetaFront::HideAll,tM.GetMorphWeightReference(BetaFront::HideAll),  90);
        AddParameter(BetaFront::AngryEyeMouth,tM.GetMorphWeightReference(BetaFront::AngryEyeMouth),  30);

        AddViseme(Viseme::MouthShape::EE, tM.GetMorphWeightReference(BetaFront::vrc_v_ee));
        AddViseme(Viseme::MouthShape::AH, tM.GetMorphWeightReference(BetaFront::vrc_v_aa));
        AddViseme(Viseme::MouthShape::UH, tM.GetMorphWeightReference(BetaFront::vrc_v_dd));
        AddViseme(Viseme::MouthShape::AR, tM.GetMorphWeightReference(BetaFront::vrc_v_rr));
        AddViseme(Viseme::MouthShape::ER, tM.GetMorphWeightReference(BetaFront::vrc_v_ch));
        AddViseme(Viseme::MouthShape::OO, tM.GetMorphWeightReference(BetaFront::vrc_v_oh));
        AddViseme(Viseme::MouthShape::SS, tM.GetMorphWeightReference(BetaFront::vrc_v_ss));
    }

    void Default(){
        // Show NukudeFace, hide BetaFront
        pM.GetObject()->Enable();
        tM.GetObject()->Disable();
    }

    void Angry(){
        // Show NukudeFace, hide BetaFront
        pM.GetObject()->Disable();
        tM.GetObject()->Enable();

        DisableBlinking();
        AddParameterFrame(BetaFront::BlushEye, 1.0f);
        AddParameterFrame(BetaFront::HideBlush, 0.0f);
        AddParameterFrame(BetaFront::HideEyeBrow, 1.0f);
        AddParameterFrame(BetaFront::HideSecondEye, 1.0f);
        AddParameterFrame(BetaFront::OwOMouth, 1.0f);
        AddMaterialFrame(Color::CRAINBOW, 0.8f);
    } 

    void Sad(){
        // Show NukudeFace, hide BetaFront
        pM.GetObject()->Enable();
        tM.GetObject()->Disable();
        
        
        AddParameterFrame(NukudeFace::Sadness, 1.0f);
        AddParameterFrame(NukudeFace::Frown, 1.0f);
        AddMaterialFrame(Color::CBLUE);
    }

    void Surprised(){
        // Show NukudeFace, hide BetaFront
        pM.GetObject()->Enable();
        tM.GetObject()->Disable();
        
        AddParameterFrame(NukudeFace::Surprised, 1.0f);
        AddParameterFrame(NukudeFace::HideBlush, 0.0f);
        AddMaterialFrame(Color::CRAINBOW);
    }
    
    void Doubt(){
        // Show NukudeFace, hide BetaFront
        pM.GetObject()->Enable();
        tM.GetObject()->Disable();
        
        AddParameterFrame(NukudeFace::Doubt, 1.0f);
    }
    
    void Frown(){
        // Show NukudeFace, hide BetaFront
        pM.GetObject()->Enable();
        tM.GetObject()->Disable();
        
        AddParameterFrame(NukudeFace::Frown, 1.0f);
    }

    void LookUp(){
        // Show NukudeFace, hide BetaFront
        pM.GetObject()->Enable();
        tM.GetObject()->Disable();
        
        AddParameterFrame(NukudeFace::LookUp, 1.0f);
    }

    void LookDown(){
        // Show NukudeFace, hide BetaFront
        pM.GetObject()->Enable();
        tM.GetObject()->Disable();
        
        AddParameterFrame(NukudeFace::LookDown, 1.0f);
    }

    void SpectrumAnalyzerCallback() override {
        AddMaterialFrame(Color::CHORIZONTALRAINBOW, 0.8f);
    }

    void AudioReactiveGradientCallback() override {
        AddMaterialFrame(Color::CHORIZONTALRAINBOW, 0.8f);
    }

    void OscilloscopeCallback() override {
        AddMaterialFrame(Color::CHORIZONTALRAINBOW, 0.8f);
    }

   void GamecubeFace(){
       AddMaterialFrame(gamecube, 1.0f);
   }

   void owo() {
    // Hide the NukudeFace and show BetaFront
    pM.GetObject()->Disable();
    tM.GetObject()->Enable();
    
    // Show BetaFront features
    AddParameterFrame(BetaFront::CircleEye, 1.0f);
    AddParameterFrame(BetaFront::OwOMouth, 1.0f);
    AddMaterialFrame(Color::CRAINBOW);
   }
public:
    ProtogenHUB75Project() : ProtogenProject(&cameras, &controller, 2, Vector2D(), Vector2D(192.0f, 94.0f), 21, 22, 11){
        scene.AddObject(pM.GetObject());
        scene.AddObject(tM.GetObject());
        scene.AddObject(deltaDisplayBackground.GetObject());

        pM.GetObject()->SetMaterial(GetFaceMaterial());
        tM.GetObject()->SetMaterial(GetFaceMaterial());
        deltaDisplayBackground.GetObject()->SetMaterial(GetFaceMaterial());

        // Initialize face visibility - show NukudeFace by default, hide BetaFront
        pM.GetObject()->Disable();
        tM.GetObject()->Enable();

        hud.SetFaceArray(faceArray);

        LinkControlParameters();
        AddMaterial(Material::Replace, &gamecube, 20, 0.0f, 1.0f);

        
        SetWiggleSpeed(5.0f);
        SetMenuWiggleSpeed(0.0f, 0.0f, 0.0f);
        SetMenuOffset(Vector2D(17.5f, -3.0f));
        SetMenuSize(Vector2D(192, 56));
    }

    void Update(float ratio) override {
        pM.Reset();
        tM.Reset();

        uint8_t mode = Menu::GetFaceState();//change by button press

        controller.SetBrightness(Menu::GetBrightness());
        controller.SetAccentBrightness(Menu::GetAccentBrightness());

#ifdef MORSEBUTTON
        SelectFaceFromMorse(mode);
#else
        SelectFace(mode);
#endif

        UpdateFace(ratio);

        gamecube.Update();

        pM.Update();
        tM.Update();

        AlignObjectFace(pM.GetObject(), -7.5f);
        AlignObjectFace(tM.GetObject(), -7.5f);

        pM.GetObject()->GetTransform()->SetPosition(GetWiggleOffset());
        pM.GetObject()->UpdateTransform();

        // tM.GetObject()->GetTransform()->SetPosition(GetWiggleOffset());
        tM.GetObject()->UpdateTransform();
    }

    void SelectFace(uint8_t code) {
        if (IsBooped() && code != 6) {
            Surprised();
            return;
        }

        switch(code) {
            case 0: owo();  break;
            case 1: Angry();    break;
            case 2: Doubt();    break;
            case 3: Frown();    break;
            case 4: LookUp();   break;
            case 5: Sad();      break;
            case 6: AudioReactiveGradientFace();    break;
            case 7: OscilloscopeFace();             break;
            case 8: GamecubeFace();                 break;
            case 9: owo();                 break;
            default: SpectrumAnalyzerFace();        break;
        }
    }

    void SelectFaceFromMorse(uint8_t code) {
        if (IsBooped() && code != 24) {
            Surprised();
            return;
        }

        switch(code) {
            case 1: Angry();        break; // [A]ngry
            case 2: Surprised();    break; // [B]lush
            case 4: Doubt();        break; // [D]oubt
            case 6: Frown();        break; // [F]rown
            case 19: Sad();         break; // [S]ad
            case 21: LookUp();      break; // Look [U]p
            case 22: LookDown();    break; // Look [V] Down
            case 24: AudioReactiveGradientFace();   break; // [X] X.X
            case 25: OscilloscopeFace();            break; // [Y] Oscilloscope
            case 26: SpectrumAnalyzerFace();        break; // [Z] Spectrum
            default: Default();     break; // [H] Happy
        }
    }
};
