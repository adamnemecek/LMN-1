#pragma once
#include <juce_gui_extra/juce_gui_extra.h>
#include "LFOParameters.h"
#include "PresetSlots.h"
#include "KnobControlledParameters.h"

class LFOParametersView
    : public juce::Component,
      public juce::ApplicationCommandTarget,
      public PresetSlots::Listener
{
public:
    LFOParametersView(KnobControlledParameters* params);

    void paint(juce::Graphics&) override;
    void resized() override;

    ApplicationCommandTarget* getNextCommandTarget() override;
    void getAllCommands(juce::Array<juce::CommandID>& commands) override;
    void getCommandInfo(juce::CommandID commandID, juce::ApplicationCommandInfo& result) override;
    bool perform(const InvocationInfo &info) override;

    void currentPresetLFOParametersChanged(LFOParameters* params) override;
    
private:
    KnobControlledParameters* parameters;
    juce::Label titleLabel;
    juce::ApplicationCommandManager commandManager;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LFOParametersView)
};

