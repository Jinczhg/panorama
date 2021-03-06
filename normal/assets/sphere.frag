/*
 * This proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 * (C) COPYRIGHT 2012 ARM Limited
 * ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 */

precision lowp float;
varying mediump vec2 myTexCoord;
uniform sampler2D sampler2d_image;
void main()
{
    gl_FragColor = texture2D(sampler2d_image,myTexCoord);
}
