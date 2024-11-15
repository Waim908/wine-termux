        ��  ��                  5  d   ��
 C S _ U A V _ C L E A R _ B U F F E R _ F L O A T _ C O D E . H L S L       0           /*
 * Copyright 2019 Philip Rebohle
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

RWBuffer<float4> dst;

struct
{
    float4 clear_value;
    int2 dst_offset;
    int2 dst_extent;
} u_info;

[numthreads(128, 1, 1)]
void main(int3 thread_id : SV_DispatchThreadID)
{
    if (thread_id.x < u_info.dst_extent.x)
        dst[u_info.dst_offset.x + thread_id.x] = u_info.clear_value;
}
   3  d   ��
 C S _ U A V _ C L E A R _ B U F F E R _ U I N T _ C O D E . H L S L         0           /*
 * Copyright 2019 Philip Rebohle
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

RWBuffer<uint4> dst;

struct
{
    uint4 clear_value;
    int2 dst_offset;
    int2 dst_extent;
} u_info;

[numthreads(128, 1, 1)]
void main(int3 thread_id : SV_DispatchThreadID)
{
    if (thread_id.x < u_info.dst_extent.x)
        dst[u_info.dst_offset.x + thread_id.x] = u_info.clear_value;
}
 O  h   ��
 C S _ U A V _ C L E A R _ 1 D _ A R R A Y _ F L O A T _ C O D E . H L S L       0           /*
 * Copyright 2019 Philip Rebohle
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

RWTexture1DArray<float4> dst;

struct
{
    float4 clear_value;
    int2 dst_offset;
    int2 dst_extent;
} u_info;

[numthreads(64, 1, 1)]
void main(int3 thread_id : SV_DispatchThreadID)
{
    if (thread_id.x < u_info.dst_extent.x)
        dst[int2(u_info.dst_offset.x + thread_id.x, thread_id.y)] = u_info.clear_value;
}
 M  h   ��
 C S _ U A V _ C L E A R _ 1 D _ A R R A Y _ U I N T _ C O D E . H L S L         0           /*
 * Copyright 2019 Philip Rebohle
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

RWTexture1DArray<uint4> dst;

struct
{
    uint4 clear_value;
    int2 dst_offset;
    int2 dst_extent;
} u_info;

[numthreads(64, 1, 1)]
void main(int3 thread_id : SV_DispatchThreadID)
{
    if (thread_id.x < u_info.dst_extent.x)
        dst[int2(u_info.dst_offset.x + thread_id.x, thread_id.y)] = u_info.clear_value;
}
   7  \   ��
 C S _ U A V _ C L E A R _ 1 D _ F L O A T _ C O D E . H L S L       0           /*
 * Copyright 2019 Philip Rebohle
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

RWTexture1D<float4> dst;

struct
{
    float4 clear_value;
    int2 dst_offset;
    int2 dst_extent;
} u_info;

[numthreads(64, 1, 1)]
void main(int3 thread_id : SV_DispatchThreadID)
{
    if (thread_id.x < u_info.dst_extent.x)
        dst[u_info.dst_offset.x + thread_id.x] = u_info.clear_value;
}
 5  \   ��
 C S _ U A V _ C L E A R _ 1 D _ U I N T _ C O D E . H L S L         0           /*
 * Copyright 2019 Philip Rebohle
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

RWTexture1D<uint4> dst;

struct
{
    uint4 clear_value;
    int2 dst_offset;
    int2 dst_extent;
} u_info;

[numthreads(64, 1, 1)]
void main(int3 thread_id : SV_DispatchThreadID)
{
    if (thread_id.x < u_info.dst_extent.x)
        dst[u_info.dst_offset.x + thread_id.x] = u_info.clear_value;
}
   W  h   ��
 C S _ U A V _ C L E A R _ 2 D _ A R R A Y _ F L O A T _ C O D E . H L S L       0           /*
 * Copyright 2019 Philip Rebohle
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

RWTexture2DArray<float4> dst;

struct
{
    float4 clear_value;
    int2 dst_offset;
    int2 dst_extent;
} u_info;

[numthreads(8, 8, 1)]
void main(int3 thread_id : SV_DispatchThreadID)
{
    if (all(thread_id.xy < u_info.dst_extent.xy))
        dst[int3(u_info.dst_offset.xy + thread_id.xy, thread_id.z)] = u_info.clear_value;
}
 U  h   ��
 C S _ U A V _ C L E A R _ 2 D _ A R R A Y _ U I N T _ C O D E . H L S L         0           /*
 * Copyright 2019 Philip Rebohle
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

RWTexture2DArray<uint4> dst;

struct
{
    uint4 clear_value;
    int2 dst_offset;
    int2 dst_extent;
} u_info;

[numthreads(8, 8, 1)]
void main(int3 thread_id : SV_DispatchThreadID)
{
    if (all(thread_id.xy < u_info.dst_extent.xy))
        dst[int3(u_info.dst_offset.xy + thread_id.xy, thread_id.z)] = u_info.clear_value;
}
   ?  \   ��
 C S _ U A V _ C L E A R _ 2 D _ F L O A T _ C O D E . H L S L       0           /*
 * Copyright 2019 Philip Rebohle
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

RWTexture2D<float4> dst;

struct
{
    float4 clear_value;
    int2 dst_offset;
    int2 dst_extent;
} u_info;

[numthreads(8, 8, 1)]
void main(int3 thread_id : SV_DispatchThreadID)
{
    if (all(thread_id.xy < u_info.dst_extent.xy))
        dst[u_info.dst_offset.xy + thread_id.xy] = u_info.clear_value;
}
 =  \   ��
 C S _ U A V _ C L E A R _ 2 D _ U I N T _ C O D E . H L S L         0           /*
 * Copyright 2019 Philip Rebohle
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

RWTexture2D<uint4> dst;

struct
{
    uint4 clear_value;
    int2 dst_offset;
    int2 dst_extent;
} u_info;

[numthreads(8, 8, 1)]
void main(int3 thread_id : SV_DispatchThreadID)
{
    if (all(thread_id.xy < u_info.dst_extent.xy))
        dst[u_info.dst_offset.xy + thread_id.xy] = u_info.clear_value;
}
   I  \   ��
 C S _ U A V _ C L E A R _ 3 D _ F L O A T _ C O D E . H L S L       0           /*
 * Copyright 2019 Philip Rebohle
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

RWTexture3D<float4> dst;

struct
{
    float4 clear_value;
    int2 dst_offset;
    int2 dst_extent;
} u_info;

[numthreads(8, 8, 1)]
void main(int3 thread_id : SV_DispatchThreadID)
{
    if (all(thread_id.xy < u_info.dst_extent.xy))
        dst[int3(u_info.dst_offset.xy, 0) + thread_id.xyz] = u_info.clear_value;
}
   G  \   ��
 C S _ U A V _ C L E A R _ 3 D _ U I N T _ C O D E . H L S L         0           /*
 * Copyright 2019 Philip Rebohle
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

RWTexture3D<uint4> dst;

struct
{
    uint4 clear_value;
    int2 dst_offset;
    int2 dst_extent;
} u_info;

[numthreads(8, 8, 1)]
void main(int3 thread_id : SV_DispatchThreadID)
{
    if (all(thread_id.xy < u_info.dst_extent.xy))
        dst[int3(u_info.dst_offset.xy, 0) + thread_id.xyz] = u_info.clear_value;
}
 