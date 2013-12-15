//
//  Shader.fsh
//  HelloOpengles
//
//  Created by Hanson on 13-12-5.
//  Copyright (c) 2013年 Hanson. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
