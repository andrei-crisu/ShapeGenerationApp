# This application generate different types of shapes:
-cogwheel polygonal contours  
-irregular polygons  
-regular polygons  
-circles,ellipsis  
-stars  
-rectangles  
-triangles  
   
     
   ![shape_generation_home](https://user-images.githubusercontent.com/68897925/155889239-ebb156f5-553b-4769-b8b2-c9dd58b52547.png) 
## In the next picture can be seen few of the shapes that can be generated:
   ![generate_all](https://user-images.githubusercontent.com/68897925/155889759-c9b43573-6820-4902-a229-9e45c10193e3.png)


## Drawing of a star:  
<i> A user can generate a star with a number of vertices between 3 and 16.     
    The second property that can be chosen by the user is **Depth** and it is a value between 10% and 90% of Radius.   
    The radius represent the distance from star center to the one of the vertices.The center point is randomly generated ,where x and y coordinates are values between -300 and 300. </i> 
  
  <i> First image shows a **5** vertices star with a depth of 60%. </i>  
  ![generate_star](https://user-images.githubusercontent.com/68897925/155890134-be02b4e5-90ff-4183-9aac-3e89c3dd9cb4.png)
    <br><br><br><br>
  <i> Second image shows a **16** vertices start with a depth of 90%. </i>
    <br>
  ![generate_star2](https://user-images.githubusercontent.com/68897925/155890138-a60a5904-c8e7-4f78-991f-e2657314c2c3.png)  
  
  <i>For simplicity reason the explanation will continue with the first example. The algorithm of star drawing is the next one:   
        1. It is generated a random number between 60 and 120 which represent the long radius.Distance from star center to a star vertex is considered a long radius.    
        2. Between every two main vertices, there is a secondary vertex. The __short radius__ is calculated in 3 steps :   
               a) it is calculated the distance from center to a line that passes through 2 main vertices. Let's call it **Dist**;    
               b) the depth in percentage given by user will be calculated as the value from **Dist**;       
               c) the __short radius__ will represent the difference between **long radius** and **depth as value**.  
        3.The third step is the generation of circumscribed circle center which is also the center of the star. **x** and **y** coordinates are generated as random values                  between -300 and 300.  
        4.To generate the polygonal contour is considering a double number of vertices for computing the  ( main vertices + secondary vertices). The angle step is computed with next relation:         
</i>     
  <p>angle_step=360/(2*nr<sub>vertices</sub>)</p>
  
<i>
  For the 5 vertices star the angle step has 36<span>&#176;</span>.Angles:<br>   
    0=0*36;<br>    
    36=1*36;<br>       
    72=2*36;<br>       
    ...<br>     
    angle=k*36;  where k <span>&#8712;</span> [0,9)<br>      
    ...<br>     
    324=9*36;<br>     
</i>
<p>
  <i>
    If <b>k</b> is even number: the point from the polygonal contour will be a main vertex with polar coordinates <b>(long radius,angle)</b>.  
    If <b>k</b> is odd number: the point from the polygonal contour will be a secondary vertex with polar coordinates <b>(short radius,angle)</b>.
  </i>
</p>
<i>
  The star will be represented by the polygonal contour that joins all these points ordered by polar coordinate <b>angle</b>. Must be specified that the points added to the contour are given in cartesian coordinates. A previous conversion is necessary.   
</i><br>


## Drawing triangles 
<b>There are 4 ways to generate triangles:</b><br>
<i>-Scalene triangle</i><br>
<i>-Isosceles triangle</i><br>
<i>-Equilateral triangle</i><br>
<i>-Not random. (In this case the user chooses the coordinates of the vertices. The algorithm implements also a collinearity check to ensure that the 3 points could be the vertices of a triangle)</i><br><br><br>
<b>In the next image can be seen a star and different types of triangles.</b>
![shape_generation_triangles_and_stars](https://user-images.githubusercontent.com/68897925/156201571-206e5a9c-cb4c-4dd4-9459-1b6b8d7fdb38.png)
<br><br>

## Drawing rectangles
<br>
<i>The main properties that can be modified by the user for rectangle generation are : top left corner, width ,height and rotation angle.</i><br>
<i>The rectangle will be represented as a 4 vertices polygonal contour. The first point will be the top left corner. If the rotation angle is not 0 then the rotation will be done after the top left corner. The other 3 vertices of the rectangle will be computed based on rotation angle, top left corner, width, and height. </i><br><br>

![shape_generation_rectangles](https://user-images.githubusercontent.com/68897925/156203677-bbe6e27e-0ae8-4c0c-a023-1397fb745747.png)
<br><br><br><br>

## Drawing cogwheels 
<br>
<i>Remark: in the next paragraphs we will refer to the space between two cogwheel teeth as <b>free space</b>

The first parameter that can be selected is the teeth number that the cogwheel will have. It will be between 8 and 60.
The second parameter is the cog base radius which is the distance from the circumscribed circle center to the tooth base. The radius can be a number between 100 and 300.

The last editable parameter is the cogwheel teeth height. It is computed as a percentage between 5% and 20% of the cogwheel base radius. It is the distance between the base and top of the cogwheel tooth.</i><br>
![shape_generation_cogs](https://user-images.githubusercontent.com/68897925/156217887-48aa18ed-5e2d-4985-a6ac-d65ec4f5ecd4.png)

<br><br>
<i>
   The next image shows the way how the algorithm from backend draws cogwheel polygonal contour. It is comparable with the one that draws a star but the repeating pattern it is bit more complex.<br>
   A repeating pattern is a pair <b>cogwheel tooth - free space</b>.
To explain the creation of polygonal contour it will be used a cogwheel with 4 pairs <b>cogwheel tooth - free space</b>. Note that it is just for theoretical reasons,because the minimal number of pattern pairs that application allow to be created is 8.<br>
   Polygonal contour will accept only vertices in cartesian coordinates and because computed points will be in polar coordinates will also be a conversion process.<br>
In this example <b>nr=4</b> ;as result the sector angle value of a 'pair' will be <b>step_angle</b>=360<span>&#176;</span>/4=90<span>&#176;</span>.
It is also necessary to mention that vertices coordinates are relative to the center of circumscribed circle.<br>

   First vertex of polygonal contour  is P<sub>1(r,<span>&#952;</span>)</sub>(base_radius,0<span>&#176;</span>).<br>
   Vertex 2 is P<sub>2(r,<span>&#952;</span>)</sub>(base_radius+tooth_height,10% of step_angle).<br>
   Vertex 3 is P<sub>3(r,<span>&#952;</span>)</sub>(base_radius+tooth_height,50% of step_angle).<br>
   Vertex 4 is P<sub>4(r,<span>&#952;</span>)</sub>(base_radius,60% of step_angle).<br><br><br>
   
   If it is considered the pair tooth-space <b></b> k,where k=0,1,2,... nr-1 than the coordinates for vertices that are part of this pattern are:<br><br>
   First vertex of pattern k  is P<sub>1(r,<span>&#952;</span>)</sub>(base_radius,k\*angle_step).<br>
   Vertex 2 of pattern k is P<sub>2(r,<span>&#952;</span>)</sub>(base_radius+tooth_height,10% of step_angle+ k\*angle_step).<br>
   Vertex 3 of pattern k is P<sub>3(r,<span>&#952;</span>)</sub>(base_radius+tooth_height,50% of step_angle+k\*angle_step).<br>
   Vertex 4 of pattern k is P<sub>4(r,<span>&#952;</span>)</sub>(base_radius,60% of step_angle+k\*angle_step).<br><br><br>
</i>

![cog_explanation](https://user-images.githubusercontent.com/68897925/156220336-a8667571-f03c-4bae-a397-e628927c94f7.png)




