/*
 *  midiFighter.cpp
 *  InputExample
 *
 *  Created by Joshua Batty on 5/08/12.
 *  Copyright 2012 Buffer Music Production. All rights reserved.
 *
 */

#include "korg.h"

//--------------------------------------------------------------
void Korg::setup() {

	// print input ports to console
	midiIn.listPorts(); // via instance
	midiOut.listPorts(); // via instance
		//ofxMidiIn::listPorts(); // via static as well
	
	// open port by number (you may need to change this)
	midiIn.openPort(0);
	midiOut.openPort(0);	// by number
		//midiIn.openPort("IAC Pure Data In");	// by name
	//midiIn.openVirtualPort("ofxMidiIn Input");	// open a virtual port
	
	// don't ignore sysex, timing, & active sense messages,
	// these are ignored by default
	midiIn.ignoreTypes(false, false, false);
	
	// add midiFighter as a listener
	midiIn.addListener(this);
	
	// print received messages to the console
	midiIn.setVerbose(true);
	
	channel = 1;
	note = 0;
	velocity = 0;
	
	i = 0;

	//Init toggles
	for(int i = 0; i < 8; i++){
		buttonsSolo[i]=false;
		buttonsMute[i]=false;
		buttonsRec[i]=false;
	}
 
}

//--------------------------------------------------------------
void Korg::newMidiMessage(ofxMidiMessage& msg) {
    //std::cout << ofxMidiMessage.getStatusString(msg.status) << endl;
    
    string statusString = ofxMidiMessage::getStatusString(msg.status);
    
    ////////////////////////////////////
    //			SLIDERS				  //
    ////////////////////////////////////
    if(statusString == "Pitch Bend"){
        if(msg.channel == 1){
            sliders[0] = msg.value;
        }
        if(msg.channel == 2){
            sliders[1] = msg.value;
        }
        if(msg.channel == 3){
            sliders[2] = msg.value;
        }
        if(msg.channel == 4){
            sliders[3] = msg.value;
        }
        if(msg.channel == 5){
            sliders[4] = msg.value;
        }
        if(msg.channel == 6){
            sliders[5] = msg.value;
        }
        if(msg.channel == 7){
            sliders[6] = msg.value;
        }
        if(msg.channel == 8){
            sliders[7] = msg.value;
        }
    }
    
    ////////////////////////////////////
    //		    	KNOBS   		  //
    ////////////////////////////////////
    // WIP
    if(statusString == "Control Change"){
        if(msg.control == 16){
            knobs[0] = msg.value;
        }
        if(msg.control == 17){
            knobs[1] = msg.value;
        }
        if(msg.control == 18){
            knobs[2] = msg.value;
        }
        if(msg.control == 19){
            knobs[3] = msg.value;
        }
        if(msg.control == 20){
            knobs[4] = msg.value;
        }
        if(msg.control == 21){
            knobs[5] = msg.value;
        }
        if(msg.control == 22){
            knobs[6] = msg.value;
        }
        if(msg.control == 23){
            knobs[7] = msg.value;
        }
    }
    
    if(statusString == "Note On"){
        //cout << "Channel:" << ofToString(msg.channel) << " Pitch:" << ofToString(msg.pitch) << endl;
        //cout << "portNum:" << ofToString(msg.portNum) << " Velocity:" << ofToString(msg.velocity) << endl << endl;

        ////////////////////////////////////
        //		    SOLO BUTTONS		  //
        ////////////////////////////////////
        if(msg.pitch == 8 && msg.velocity == 127){
            buttonsSolo[0] = true;
        } else if(msg.pitch == 8 && msg.velocity == 0){
            buttonsSolo[0] = false;
        }
        if(msg.pitch == 9 && msg.velocity == 127){
            buttonsSolo[1] = true;
        } else if(msg.pitch == 9 && msg.velocity == 0){
            buttonsSolo[1] = false;
        }
        if(msg.pitch == 10 && msg.velocity == 127){
            buttonsSolo[2] = true;
        } else if(msg.pitch == 10 && msg.velocity == 0){
            buttonsSolo[2] = false;
        }
        if(msg.pitch == 11 && msg.velocity == 127){
            buttonsSolo[3] = true;
        } else if(msg.pitch == 11 && msg.velocity == 0){
            buttonsSolo[3] = false;
        }
        if(msg.pitch == 12 && msg.velocity == 127){
            buttonsSolo[4] = true;
        } else if(msg.pitch == 12 && msg.velocity == 0){
            buttonsSolo[4] = false;
        }
        if(msg.pitch == 13 && msg.velocity == 127){
            buttonsSolo[5] = true;
        } else if(msg.pitch == 13 && msg.velocity == 0){
            buttonsSolo[5] = false;
        }
        if(msg.pitch == 14 && msg.velocity == 127){
            buttonsSolo[6] = true;
        } else if(msg.pitch == 14 && msg.velocity == 0){
            buttonsSolo[6] = false;
        }
        if(msg.pitch == 15 && msg.velocity == 127){
            buttonsSolo[7] = true;
        } else if(msg.pitch == 15 && msg.velocity == 0){
            buttonsSolo[7] = false;
        }
        
        ////////////////////////////////////
        //		    MUTE BUTTONS		  //
        ////////////////////////////////////
        if(msg.pitch == 16 && msg.velocity == 127){
            buttonsMute[0] = true;
        } else if(msg.pitch == 16 && msg.velocity == 0){
            buttonsMute[0] = false;
        }
        if(msg.pitch == 17 && msg.velocity == 127){
            buttonsMute[1] = true;
        } else if(msg.pitch == 17 && msg.velocity == 0){
            buttonsMute[1] = false;
        }
        if(msg.pitch == 18 && msg.velocity == 127){
            buttonsMute[2] = true;
        } else if(msg.pitch == 18 && msg.velocity == 0){
            buttonsMute[2] = false;
        }
        if(msg.pitch == 19 && msg.velocity == 127){
            buttonsMute[3] = true;
        } else if(msg.pitch == 19 && msg.velocity == 0){
            buttonsMute[3] = false;
        }
        if(msg.pitch == 20 && msg.velocity == 127){
            buttonsMute[4] = true;
        } else if(msg.pitch == 20 && msg.velocity == 0){
            buttonsMute[4] = false;
        }
        if(msg.pitch == 21 && msg.velocity == 127){
            buttonsMute[5] = true;
        } else if(msg.pitch == 21 && msg.velocity == 0){
            buttonsMute[5] = false;
        }
        if(msg.pitch == 22 && msg.velocity == 127){
            buttonsMute[6] = true;
        } else if(msg.pitch == 22 && msg.velocity == 0){
            buttonsMute[6] = false;
        }
        if(msg.pitch == 23 && msg.velocity == 127){
            buttonsMute[7] = true;
        } else if(msg.pitch == 23 && msg.velocity == 0){
            buttonsMute[7] = false;
        }
        
        ////////////////////////////////////
        //		    RECORD BUTTONS		  //
        ////////////////////////////////////
        if(msg.pitch == 0 && msg.velocity == 127){
            buttonsRec[0] = true;
        } else if(msg.pitch == 0 && msg.velocity == 0){
            buttonsRec[0] = false;
        }
        if(msg.pitch == 1 && msg.velocity == 127){
            buttonsRec[1] = true;
        } else if(msg.pitch == 1 && msg.velocity == 0){
            buttonsRec[1] = false;
        }
        if(msg.pitch == 2 && msg.velocity == 127){
            buttonsRec[2] = true;
        } else if(msg.pitch == 2 && msg.velocity == 0){
            buttonsRec[2] = false;
        }
        if(msg.pitch == 3 && msg.velocity == 127){
            buttonsRec[3] = true;
        } else if(msg.pitch == 3 && msg.velocity == 0){
            buttonsRec[3] = false;
        }
        if(msg.pitch == 4 && msg.velocity == 127){
            buttonsRec[4] = true;
        } else if(msg.pitch == 4 && msg.velocity == 0){
            buttonsRec[4] = false;
        }
        if(msg.pitch == 5 && msg.velocity == 127){
            buttonsRec[5] = true;
        } else if(msg.pitch == 5 && msg.velocity == 0){
            buttonsRec[5] = false;
        }
        if(msg.pitch == 6 && msg.velocity == 127){
            buttonsRec[6] = true;
        } else if(msg.pitch == 6 && msg.velocity == 0){
            buttonsRec[6] = false;
        }
        if(msg.pitch == 7 && msg.velocity == 127){
            buttonsRec[7] = true;
        } else if(msg.pitch == 7 && msg.velocity == 0){
            buttonsRec[7] = false;
        }
        
        
        ////////////////////////////////////
        //		    LEFT BUTTONS		  //
        ////////////////////////////////////
        if(msg.pitch == 46 && msg.velocity == 127){
            buttonTrackLeft = true;
        } else if(msg.pitch == 46 && msg.velocity == 0){
            buttonTrackLeft = false;
        }
        if(msg.pitch == 47 && msg.velocity == 127){
            buttonTrackRight = true;
        } else if(msg.pitch == 47 && msg.velocity == 0){
            buttonTrackRight = false;
        }
        if(msg.pitch == 89 && msg.velocity == 127){
            buttonCycle = true;
        } else if(msg.pitch == 89 && msg.velocity == 0){
            buttonCycle = false;
        }
        /*if(msg.pitch == 60 && msg.velocity == 127){
         buttonMarkerSet = true;
         } else if(msg.pitch == 60 && msg.velocity == 0){
         buttonMarkerSet = false;
         }
         if(msg.pitch == 61 && msg.velocity == 127){
         buttonMarkerLeft = true;
         } else if(msg.pitch == 61 && msg.velocity == 0){
         buttonMarkerLeft = false;
         }
         if(msg.pitch == 62 && msg.velocity == 127){
         buttonMarkerRight = true;
         } else if(msg.pitch == 62 && msg.velocity == 0){
         buttonMarkerRight = false;
         }*/
        if(msg.pitch == 91 && msg.velocity == 127){
            buttonRewind = true;
        } else if(msg.pitch == 91 && msg.velocity == 0){
            buttonRewind = false;
        }
        if(msg.pitch == 92 && msg.velocity == 127){
            buttonFastForward = true;
        } else if(msg.pitch == 92 && msg.velocity == 0){
            buttonFastForward = false;
        }
        if(msg.pitch == 93 && msg.velocity == 127){
            buttonStop = true;
        } else if(msg.pitch == 93 && msg.velocity == 0){
            buttonStop = false;
        }
        if(msg.pitch == 94 && msg.velocity == 127){
            buttonPlay = true;
        } else if(msg.pitch == 94 && msg.velocity == 0){
            buttonPlay = false;
        }
        if(msg.pitch == 95 && msg.velocity == 127){
            buttonRecord = true;
        } else if(msg.pitch == 95 && msg.velocity == 0){
            buttonRecord = false;
        }
    }
}


//--------------------------------------------------------------
void Korg::update() {
    bool sendMidi = true;
    if(sendMidi == true){
        int channel = 1;

        // send Solo Buttons
        for(i = 0; i <= 8; i++){
            int outPitch = i + 8;
            int outVelocity = buttonsSolo[i] * 127;
            midiOut.sendNoteOn(channel, outPitch, outVelocity);
        }
        
        // send Mute Buttons
        for(i = 0; i <= 8; i++){
            int outPitch = i + 16;
            int outVelocity = buttonsMute[i] * 127;
            midiOut.sendNoteOn(channel, outPitch, outVelocity);
        }
        
        // send Rec Buttons
        for(i = 0; i <= 8; i++){
            int outPitch = i;
            int outVelocity = buttonsRec[i] * 127;
            midiOut.sendNoteOn(channel, outPitch, outVelocity);
        }
        
        // send Left Buttons
        midiOut.sendNoteOn(channel, 46, buttonTrackLeft * 127);
        midiOut.sendNoteOn(channel, 47, buttonTrackRight * 127);
        midiOut.sendNoteOn(channel, 89, buttonCycle * 127);
        midiOut.sendNoteOn(channel, 91, buttonRewind * 127);
        midiOut.sendNoteOn(channel, 92, buttonFastForward * 127);
        midiOut.sendNoteOn(channel, 93, buttonStop * 127);
        midiOut.sendNoteOn(channel, 94, buttonPlay * 127);
        midiOut.sendNoteOn(channel, 95, buttonRecord * 127);

    }

}

//--------------------------------------------------------------
void Korg::draw() {

    
	ofSetColor(155,0,0);

    ofNoFill();
    ofDrawRectangle(0,30,ofGetWidth(),70);
    ofDrawRectangle(0,110,ofGetWidth(),ofGetHeight()-120);

    ofSetColor(0);
    ofDrawBitmapString("KORG NANO KONTROL 2 ", 40,20);

    //Track
    ofDrawBitmapString("trackLeft = " + ofToString(buttonTrackLeft), 40,50);
    ofDrawBitmapString("trackRight = " + ofToString(buttonTrackRight), 170,50);
    
    //Maker
    ofDrawBitmapString("cycle = " + ofToString(buttonCycle), 40,70);
    ofDrawBitmapString("markerSet = " + ofToString(buttonMarkerSet), 310,70);
    ofDrawBitmapString("markerLeft = " + ofToString(buttonMarkerLeft), 450,70);
    ofDrawBitmapString("markerRight = " + ofToString(buttonMarkerRight), 590,70);
    
    //Transport
    ofDrawBitmapString("Rewind = " + ofToString(buttonRewind), 40,90);
    ofDrawBitmapString("FastForward = " + ofToString(buttonFastForward), 170,90);
    ofDrawBitmapString("Stop = " + ofToString(buttonStop), 310,90);
    ofDrawBitmapString("Play = " + ofToString(buttonPlay), 450,90);
    ofDrawBitmapString("Record = " + ofToString(buttonRecord), 590,90);


    //Sliders
    ofDrawBitmapString("slider1 = " + ofToString(sliders[0]), 40,130);
    ofDrawBitmapString("slider2 = " + ofToString(sliders[1]), 40,150);
    ofDrawBitmapString("slider3 = " + ofToString(sliders[2]), 40,170);
    ofDrawBitmapString("slider4 = " + ofToString(sliders[3]), 40,190);
    ofDrawBitmapString("slider5 = " + ofToString(sliders[4]), 40,210);
    ofDrawBitmapString("slider6 = " + ofToString(sliders[5]), 40,230);
    ofDrawBitmapString("slider7 = " + ofToString(sliders[6]), 40,250);
    ofDrawBitmapString("slider8 = " + ofToString(sliders[7]), 40,270);
    
    //Knobs
    ofDrawBitmapString("knobs1 = " + ofToString(knobs[0]), 180,130);
    ofDrawBitmapString("knobs2 = " + ofToString(knobs[1]), 180,150);
    ofDrawBitmapString("knobs3 = " + ofToString(knobs[2]), 180,170);
    ofDrawBitmapString("knobs4 = " + ofToString(knobs[3]), 180,190);
    ofDrawBitmapString("knobs5 = " + ofToString(knobs[4]), 180,210);
    ofDrawBitmapString("knobs6 = " + ofToString(knobs[5]), 180,230);
    ofDrawBitmapString("knobs7 = " + ofToString(knobs[6]), 180,250);
    ofDrawBitmapString("knobs8 = " + ofToString(knobs[7]), 180,270);
    
    //Solo Buttons
    ofDrawBitmapString("SoloButton1 = " + ofToString(buttonsSolo[0]), 320,130);
    ofDrawBitmapString("SoloButton2 = " + ofToString(buttonsSolo[1]), 320,150);
    ofDrawBitmapString("SoloButton3 = " + ofToString(buttonsSolo[2]), 320,170);
    ofDrawBitmapString("SoloButton4 = " + ofToString(buttonsSolo[3]), 320,190);
    ofDrawBitmapString("SoloButton5 = " + ofToString(buttonsSolo[4]), 320,210);
    ofDrawBitmapString("SoloButton6 = " + ofToString(buttonsSolo[5]), 320,230);
    ofDrawBitmapString("SoloButton7 = " + ofToString(buttonsSolo[6]), 320,250);
    ofDrawBitmapString("SoloButton8 = " + ofToString(buttonsSolo[7]), 320,270);
    
    //Mute Buttons
    ofDrawBitmapString("MuteButton1 = " + ofToString(buttonsMute[0]), 460,130);
    ofDrawBitmapString("MuteButton2 = " + ofToString(buttonsMute[1]), 460,150);
    ofDrawBitmapString("MuteButton3 = " + ofToString(buttonsMute[2]), 460,170);
    ofDrawBitmapString("MuteButton4 = " + ofToString(buttonsMute[3]), 460,190);
    ofDrawBitmapString("MuteButton5 = " + ofToString(buttonsMute[4]), 460,210);
    ofDrawBitmapString("MuteButton6 = " + ofToString(buttonsMute[5]), 460,230);
    ofDrawBitmapString("MuteButton7 = " + ofToString(buttonsMute[6]), 460,250);
    ofDrawBitmapString("MuteButton8 = " + ofToString(buttonsMute[7]), 460,270);
    
    //Record Buttons
    ofDrawBitmapString("RecButton1 = " + ofToString(buttonsRec[0]), 600,130);
    ofDrawBitmapString("RecButton2 = " + ofToString(buttonsRec[1]), 600,150);
    ofDrawBitmapString("RecButton3 = " + ofToString(buttonsRec[2]), 600,170);
    ofDrawBitmapString("RecButton4 = " + ofToString(buttonsRec[3]), 600,190);
    ofDrawBitmapString("RecButton5 = " + ofToString(buttonsRec[4]), 600,210);
    ofDrawBitmapString("RecButton6 = " + ofToString(buttonsRec[5]), 600,230);
    ofDrawBitmapString("RecButton7 = " + ofToString(buttonsRec[6]), 600,250);
    ofDrawBitmapString("RecButton8 = " + ofToString(buttonsRec[7]), 600,270);
    
	
}

//--------------------------------------------------------------
void Korg::exit() {
	
	// clean up
	midiIn.closePort();
	midiIn.removeListener(this);
}
