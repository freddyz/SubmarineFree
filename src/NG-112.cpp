#include "SubmarineFree.hpp"

struct NG_112 : Module {
	static const int deviceCount = 12;
	enum ParamIds {
		NUM_PARAMS
	};
	enum InputIds {
		INPUT_1,
		INPUT_2,
		INPUT_3,
		INPUT_4,
		INPUT_5,
		INPUT_6,
		INPUT_7,
		INPUT_8,
		INPUT_9,
		INPUT_10,
		INPUT_11,
		INPUT_12,
		NUM_INPUTS
	};
	enum OutputIds {
		OUTPUT_1,
		OUTPUT_2,
		OUTPUT_3,
		OUTPUT_4,
		OUTPUT_5,
		OUTPUT_6,
		OUTPUT_7,
		OUTPUT_8,
		OUTPUT_9,
		OUTPUT_10,
		OUTPUT_11,
		OUTPUT_12,
		NUM_OUTPUTS
	};
	enum LightIds {
		NUM_LIGHTS
	};

	NG_112() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {}
	void step() override;
};

void NG_112::step() {
	for (int i = 0; i < deviceCount; i++) {
		outputs[OUTPUT_1 + i].value = (inputs[INPUT_1 + i].value < 2.5f) * 5.0f;
	}
}

struct NG112 : ModuleWidget {
	NG112(NG_112 *module) : ModuleWidget(module) {
		setPanel(SVG::load(assetPlugin(plugin, "res/NG-112.svg")));

		for (int i = 0; i < NG_112::deviceCount; i++) {
			int offset = 29 * i;
			addInput(Port::create<sub_port_blue>(Vec(3.5,19 + offset), Port::INPUT, module, NG_112::INPUT_1 + i));

			addOutput(Port::create<sub_port_blue>(Vec(61.5,19 + offset), Port::OUTPUT, module, NG_112::OUTPUT_1 + i));
		}
	}
};

Model *modelNG112 = Model::create<NG_112, NG112>("SubmarineFree", "NG-112", "NG-112 Not Gates", LOGIC_TAG, MULTIPLE_TAG);