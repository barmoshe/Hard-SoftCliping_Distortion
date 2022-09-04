/*
 ==============================================================================
 
 Distor.cpp
 Created: 3 Sep 2022 6:19:11pm
 Author:  Bar moshe
 
 ==============================================================================
 */

#include "Distor.h"

template <typename SampleType>
Distor<SampleType>::Distor()
{
    
}
template <typename SampleType>
void Distor<SampleType>::prepare(juce::dsp::ProcessSpec& spec)
{
    sampleRate=spec.sampleRate;
    reset();
}
template <typename SampleType>
void Distor<SampleType>::reset()
{
    if(sampleRate<=0) return;
    driveVal.reset(sampleRate, 0.02);
    driveVal.setTargetValue(0.0);
    
    mixVal.reset(sampleRate, 0.02);
    mixVal.setTargetValue(1.0);
    
    outputVal.reset(sampleRate, 0.02);
    outputVal.setTargetValue(0.0);
    
}
template <typename SampleType>
void Distor<SampleType>::setDistortionType(dType d)
{
    switch(d)
    {
        case hardClip:
            currentDist=hardClip;
            break;
        case softClip:
            currentDist=softClip;
            break;
        case satu:
            currentDist=satu;
            break;
    }
}
template <typename SampleType>
void Distor<SampleType>::setDriveValue(SampleType newD)
{
    driveVal.setTargetValue(newD);
}
template <typename SampleType>
void Distor<SampleType>::setMixValue(SampleType newM)
{
    mixVal.setTargetValue(newM);

}
template <typename SampleType>
void Distor<SampleType>::setOutputValue(SampleType newO)
{
    outputVal.setTargetValue(newO);

}
template class Distor<float>;
template class Distor<double>;


