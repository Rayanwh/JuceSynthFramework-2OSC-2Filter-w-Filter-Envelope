/*
  ==============================================================================

    Filter2.h
    Created: 20 Nov 2018 7:08:28pm
    Author:  Dianne Campbell

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
 */
class Filter2    : public Component
{
public:
    Filter2(JuceSynthFrameworkAudioProcessor&);
    ~Filter2();
    
    void paint (Graphics&) override;
    void resized() override;
    
private:
    Slider filter2Cutoff;
    Slider filter2Res;
    
    ComboBox filter2Menu;
    
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> filter2TypeVal;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filter2Val;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> res2Val;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    JuceSynthFrameworkAudioProcessor& processor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Filter2)
};
