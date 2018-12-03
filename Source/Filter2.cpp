/*
  ==============================================================================

    Filter2.cpp
    Created: 20 Nov 2018 7:08:28pm
    Author:  Dianne Campbell

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Filter2.h"

//==============================================================================
Filter2::Filter2(JuceSynthFrameworkAudioProcessor& p) :
processor(p)
{
    setSize(200, 200);
    
    //filter2Menu.addItem("Low Pass", 1);
    //filter2Menu.addItem("High Pass", 2);
    //filter2Menu.addItem("Band Pass", 3);
    //filter2Menu.setJustificationType(Justification::centred);
    //addAndMakeVisible(&filter2Menu);
    //filter2TypeVal = new AudioProcessorValueTreeState::ComboBoxAttachment (processor.tree, "filter2Type", filter2Menu);
    
    filter2Cutoff.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filter2Cutoff.setRange(20.0, 10000.0);
    filter2Cutoff.setValue (400.0);
    filter2Cutoff.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&filter2Cutoff);
    filter2Val = new AudioProcessorValueTreeState::SliderAttachment (processor.tree, "filter2Cutoff", filter2Cutoff);
    //filter2Cutoff.setSkewFactorFromMidPoint(1000.0);
    
    filter2Res.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filter2Res.setRange(1, 5);
    filter2Res.setValue(1);
    filter2Res.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&filter2Res);
    res2Val = new AudioProcessorValueTreeState::SliderAttachment (processor.tree, "filter2Res", filter2Res);
}

Filter2::~Filter2()
{
}

void Filter2::paint (Graphics& g)
{
    //background ui stuff
    juce::Rectangle<int> titleArea (0, 10, getWidth(), 20);
    
    g.fillAll (Colours::black);
    g.setColour(Colours::white);
    g.drawText("Filter2", titleArea, Justification::centredTop);
    
    juce::Rectangle <float> area (25, 25, 150, 150);
    
    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void Filter2::resized()
{
    //need to come back and dynamically set these...ok for now
    juce::Rectangle<int> area = getLocalBounds().reduced(40);
    
    filter2Menu.setBounds(area.removeFromTop(20));
    filter2Cutoff.setBounds (30, 100, 70, 70);
    filter2Res.setBounds (100, 100, 70, 70);
}
