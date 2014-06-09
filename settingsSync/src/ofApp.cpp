#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	    // dmx
	dmxColor = 70;
	dmxDimmer = 255;
	dmxShutter = 250;


    // defaults
    mouseX = mouseY = 0;
    sliderValX = 0.69f;
    sliderValY = 30;
    toggleValA = true;
    toggleValB = false;
    selectListIndex = 1;
    string ddOptions[] = {"Option 1", "Option 2", "Option 3", "Option 4", "Option 5"};
    string description = "Text that can be Displayed in a paragraph form (i.e. this should be wrapping at the width I have set).";
    
    
    // settings
    settings.loadSettings("settings.xml", false, true); // savefile, default font, use mouse
    settings.loadFonts("stan0755.ttf", "VAGRoundedStd-Light.otf", 10, 20, true); // optional
    settings.setupSendOSC("localhost", 3333); // optional ( change ip to match your ios device!!!)
    settings.setupReceiveOSC(5556); // optional (receives from iOS device running ofxTouchGUIExampleIOS)
    //settings.setWindowPosition(ofGetWidth()-250, 0); // optional
	settings.setItemHeight(50);
	settings.setItemWidth(300);


    // add controls
    settings.addTitleText("Niners Zone " + ofToString(OFXTOUCHGUI_VERSION));
	settings.addSlider("DMX COLOR", &dmxColor, 0, 255);
	settings.addSlider("DMX DIMMER", &dmxDimmer, 0, 255);
	settings.addSlider("DMX SHUTTER", &dmxShutter, 0, 255);
    //settings.addSlider("SLIDER X", &sliderValX, 0.0f, 1.0f);
    //settings.addSlider("SLIDER Y", &sliderValY, 0, 255);
    settings.addDropDown("DROPDOWN LIST A", 5, ddOptions);
    //settings.addDropDown("DROPDOWN LIST B", 4, &selectListIndex, ddOptions);
    settings.addToggleButton("TOGGLE A", &toggleValA);
    settings.addToggleButton("TOGGLE B", &toggleValB);
    settings.addText(description);
    settings.setItemSize(200, 100);
    graph= settings.addDataGraph("GRAPH MOUSE X", 500, 400, 50, 300, 200);
    graph->setCustomRange(0, ofGetWidth());
    settings.setItemSize(200, 25);
    settings.addButton("SAVE");
    settings.addButton("RESET");

    
    // adds a listener to all gui items, pointing to onGuiChanged();
    settings.addEventListenerAllItems(this);
}

//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::draw(){

    settings.draw();
}

void ofApp::onGUIChanged(ofxTouchGUIEventArgs& args) {//const void* sender, string &buttonLabel) {
    
    ofxTouchGUIBase* target = args.target;
    string buttonLabel = target->getLabel();
        
    // or just use the label as the identifier
    if(buttonLabel == "SAVE") {
        settings.saveSettings();
    }
    else if(buttonLabel == "RESET") {
        settings.resetDefaultValues();

		settings.getSettingsJSON();
    }    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch (key) {
        case ' ':
            settings.toggleDisplay();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	graph->insertValue(x);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
