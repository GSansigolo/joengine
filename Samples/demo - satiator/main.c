/*
** Jo Sega Saturn Engine
** Copyright (c) 2012-2020, Johannes Fetz (johannesfetz@gmail.com)
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**     * Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**     * Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in the
**       documentation and/or other materials provided with the distribution.
**     * Neither the name of the Johannes Fetz nor the
**       names of its contributors may be used to endorse or promote products
**       derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL Johannes Fetz BE LIABLE FOR ANY
** DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
** ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <jo/jo.h>

void			my_draw(void)
{
    jo_set_printf_color_index(JO_COLOR_INDEX_Red);
	jo_sprite_draw3D(0, 0, 0, 500);
    if(s_mode(s_api) == 0)
	{
		jo_printf(12, 20,   "Satiator Detected");
		int result = 0;
		result = s_opendir(".");
		if(result != 0)
		{
			jo_printf(9,  22,"Satiator Is Not Working");
		}
		else 
		{
			jo_printf(11, 22,  "Satiator Is Working");
		}
	} else
	{
	    jo_printf(10, 20, "Satiator Not Detected");
	}
}

void my_background()
{
    jo_img      bg;

    bg.data = NULL;
    jo_tga_loader(&bg, "BG", "BG.TGA", JO_COLOR_Transparent);
    jo_set_background_sprite(&bg, 0, 0);
    jo_free_img(&bg);
}

void			jo_main(void)
{
	jo_core_init(JO_COLOR_White);
	my_background();

	jo_core_add_callback(my_draw);
	jo_core_run();
}

/*
** END OF FILE
*/
