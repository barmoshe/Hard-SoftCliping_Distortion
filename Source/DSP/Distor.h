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
    enum dType { hardClip, softClip, satu };
    Distor();
    void prepare(juce::dsp::ProcessSpec& spec);
    void reset();
    void setDistortionType(dType d);
    template <typename ProcessContext>
    void process(const ProcessContext& context)noexcept
    {
        const auto& inputBlock = context.getInputBlock();
        auto& outputBlock      = context.getOutputBlock();
        const auto numChannels = outputBlock.getNumChannels();
        const auto numSamples  = outputBlock.getNumSamples();
        
        jassert (inputBlock.getNumChannels() == numChannels);
        jassert (inputBlock.getNumSamples()  == numSamples);
        
        for (size_t channel = 0; channel < numChannels; ++channel)
        {
            auto* inputSamples  = inputBlock .getChannelPointer (channel);
            auto* outputSamples = outputBlock.getChannelPointer (channel);
            
            for (size_t i = 0; i < numSamples; ++i)
            {
                outputSamples[i] = processSample(inputSamples[i]);
            }
        }
        
    }
    SampleType processSample(SampleType inputSample)noexcept
    {
        switch(currentDist)
        {
            case hardClip:
                return processHardClip(inputSample);
            case softClip:
                return processSoftClip(inputSample);
            case satu:
                return processSatu(inputSample);
        }
    }
    SampleType processHardClip(SampleType inputSample)
    {
        float newSample=inputSample*driveVal.getNextValue();
        if(std::abs(newSample)>0.99)
        {
            newSample=0.99/std::abs(newSample);
        }
        auto mix =((1.0- mixVal.getNextValue())*inputSample)+(newSample*mixVal.getNextValue());
        
        return mix*outputVal.getNextValue();
    }
    SampleType processSoftClip(SampleType inputSample)
    {
        return inputSample;
    }
    SampleType processSatu(SampleType inputSample)
    {
        return inputSample;
    }
    void setDriveValue(SampleType newD);
    void setMixValue(SampleType newM);
    void setOutputValue(SampleType newO);
    
private:
    juce::SmoothedValue<float> driveVal;
    juce::SmoothedValue<float> mixVal;
    juce::SmoothedValue<float> outputVal;
    float sampleRate;
    dType currentDist=dType::hardClip;
    
    
};
