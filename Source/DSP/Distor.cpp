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
    
}
template <typename SampleType>
void Distor<SampleType>::reset()
{
    
}

template class Distor<float>;
template class Distor<double>;


