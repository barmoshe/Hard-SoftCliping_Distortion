/*
 ==============================================================================
 
 Distor.h
 Created: 3 Sep 2022 6:19:11pm
 Author:  Bar moshe
 
 ==============================================================================
 */
#pragma once
#include <JuceHeader.h>
template <typename SampleType>

class Distor
{
public:
    
    Distor();
    void prepare(juce::dsp::ProcessSpec& spec);
    void reset();
    void process(const processContext& context)noexcept;
    
};
