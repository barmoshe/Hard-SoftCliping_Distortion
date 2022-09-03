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
    template <typename ProcessContext>
    void process(const ProcessContext& context)noexcept
    {
        
    }
    void processSample(SampleType inputSample)noexcept
    {
        
    }
};
