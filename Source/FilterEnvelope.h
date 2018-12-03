/*
  ==============================================================================

    FilterEnvelope.h
    Created: 2 Dec 2018 7:48:05pm
    Author:  Dianne Campbell

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class FilterEnvelope    : public Component
{
public:
    FilterEnvelope(JuceSynthFrameworkAudioProcessor&);
    ~FilterEnvelope();

    void paint (Graphics&) override;
    void resized() override;
    

private:
    Slider fattackSlider;
    Slider fdecaySlider;
    Slider fsustainSlider;
    Slider freleaseSlider;
    
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> fattackVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> fdecayVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> fsustainVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> freleaseVal;
    
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    JuceSynthFrameworkAudioProcessor& processor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterEnvelope)
};
