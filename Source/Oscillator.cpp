/*
  ==============================================================================

    Oscillator.cpp
    Created: 11 Jan 2018 1:41:05pm
    Author:  Joshua Hodge

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"

//==============================================================================
Oscillator::Oscillator(JuceSynthFrameworkAudioProcessor& p) :
processor(p)
{
    setSize(200, 200);
    
    oscMenu.addItem("Square", 1);
    oscMenu.addItem("Saw", 2);
    //oscMenu.addItem("Sine", 3);
    oscMenu.setJustificationType(Justification::centred);
    addAndMakeVisible(&oscMenu);
    
    waveSelection = new AudioProcessorValueTreeState::ComboBoxAttachment (processor.tree, "wavetype", oscMenu);
    
    //slider initialization values
    Blend1slider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    Blend1slider.setRange(0.0f, 1.0f);
    Blend1slider.setValue(1.0f);
    Blend1slider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    Blend1slider.setColour (Slider::thumbColourId, Colour (0xff9671b9));
    Blend1slider.setColour (Slider::rotarySliderFillColourId, Colour (0xff9671b9));
    addAndMakeVisible(&Blend1slider);
    
    //sends value of the sliders to the tree state in the processor
    blend1Val = new AudioProcessorValueTreeState::SliderAttachment (processor.tree, "blend1", Blend1slider);
}

Oscillator::~Oscillator()
{
}

void Oscillator::paint (Graphics& g)
{
    //background stuff
    juce::Rectangle<int> titleArea (0, 10, getWidth(), 20);
    
    g.fillAll (Colours::black);
    g.setColour(Colours::white);
    g.drawText("Oscillator One", titleArea, Justification::centredTop);
    
    
    juce::Rectangle <float> area (25, 25, 150, 150);
    
    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void Oscillator::resized()
{
    juce::Rectangle<int> area = getLocalBounds().reduced(40);
    oscMenu.setBounds(area.removeFromTop(20));
    
    
    int sliderWidth = 125;
    int sliderHeight = 75;
    
    //draw sliders by reducing area from rectangle above
    Blend1slider.setBounds (area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
}
