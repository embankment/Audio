/* Audio Library for Teensy 3.X
 * Copyright (c) 2014, Paul Stoffregen, paul@pjrc.com
 *
 * Development of this audio library was funded by PJRC.COM, LLC by sales of
 * Teensy and Audio Adaptor boards.  Please support PJRC's efforts to develop
 * open source software by purchasing Teensy or other PJRC products.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, development funding notice, and this permission
 * notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 
   Combine analog signals with bitwise expressions like OXR. Combining two simple oscillators results in interesting new waveforms, 
   Combining white noise or dynamic incoming audio results in aggressive digital distortion.
 
 */

#ifndef effect_digital_combine_h_
#define effect_digital_combine_h_
#include "AudioStream.h"
#include "utility/dspinst.h"

#define OR      0
#define XOR  1
#define AND    2
#define MODULO  3

class AudioEffectDigitalCombine : 
public AudioStream
{
public:
	AudioEffectDigitalCombine() : 
	AudioStream(2, inputQueueArray),mode_sel(OR) { }
	
	  void mode(short mode_in) {
	  	if (mode_in>3){
	  		mode_in=3;
	  	}
	  	mode_sel=mode_in;
	  }

	virtual void update(void);
private:
	short mode_sel;
	audio_block_t *inputQueueArray[2];
};

#endif
