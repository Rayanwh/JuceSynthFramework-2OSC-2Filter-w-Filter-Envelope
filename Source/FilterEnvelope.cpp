/*
  ==============================================================================

    FilterEnvelope.cpp
    Created: 2 Dec 2018 7:48:05pm
    Author:  Dianne Campbell

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "FilterEnvelope.h"

//==============================================================================
FilterEnvelope::FilterEnvelope(JuceSynthFrameworkAudioProcessor& p) :
processor(p)
{
    setSize(200, 200);
    
        //slider initialization values
        fattackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
        fattackSlider.setRange(0.1f, 5000.0f);
        fattackSlider.setValue(0.1f);
        fattackSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        addAndMakeVisible(&fattackSlider);
    
        fdecaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
        fdecaySlider.setRange(1.0f, 2000.0f);
        fdecaySlider.setValue(1.0f);
        fdecaySlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        addAndMakeVisible(&fdecaySlider);
    
        fsustainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
        fsustainSlider.setRange(0.0f, 1.0f);
        fsustainSlider.setValue(0.8f);
        fsustainSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        addAndMakeVisible(&fsustainSlider);
    
        freleaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
        freleaseSlider.setRange(0.1f, 5000.0f);
        freleaseSlider.setValue(0.8f);
        freleaseSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
        addAndMakeVisible(&freleaseSlider);
    
        //sends value of the sliders to the tree state in the processor
        fattackVal = new AudioProcessorValueTreeState::SliderAttachment (processor.tree, "fattack", fattackSlider);
        fdecayVal = new AudioProcessorValueTreeState::SliderAttachment (processor.tree, "fdecay", fdecaySlider);
        fsustainVal = new AudioProcessorValueTreeState::SliderAttachment (processor.tree, "fsustain", fsustainSlider);
        freleaseVal = new AudioProcessorValueTreeState::SliderAttachment (processor.tree, "frelease", freleaseSlider);
}

FilterEnvelope::~FilterEnvelope()
{
}

void FilterEnvelope::paint (Graphics& g)
{
    //fancy stuff for the UI background etc
    juce::Rectangle<int> titleArea (0, 10, getWidth(), 20);
    
    g.fillAll (Colours::black);
    g.setColour(Colours::white);
    g.drawText("Filter Envelope", titleArea, Justification::centredTop);
    
    //static positioning for now due to time, make dynamic later
    g.drawText ("A", 53, 150, 20, 20, Justification::centredTop);
    g.drawText ("D", 77, 150, 20, 20, Justification::centredTop);
    g.drawText ("S", 103, 150, 20, 20, Justification::centredTop);
    g.drawText ("R", 128, 150, 20, 20, Justification::centredTop);
    
    juce::Rectangle <float> area (25, 25, 150, 150);
    
    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void FilterEnvelope::resized()
{
    //draws the sliders...we use a rectangle object to dynamically size the UI (if we want to resize for IPad etc without needing to change ALL settings
    juce::Rectangle<int> area = getLocalBounds().reduced(50);
    
    int sliderWidth = 25;
    int sliderHeight = 175;
    
    //draw sliders by reducing area from rectangle above
    fattackSlider.setBounds (area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    fdecaySlider.setBounds (area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    fsustainSlider.setBounds (area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    freleaseSlider.setBounds (area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
}
