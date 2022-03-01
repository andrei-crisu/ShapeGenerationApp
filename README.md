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


## Generation of a star:  
<i> A user can generate a star with a number of vertices between 3 and 16.     
    The second property that can be chosen by the user is **Depth** and it is a value between 10% and 90% of Radius.   
    The radius represent the distance from star center to the one of the vertices.The center point is randomly generated ,where x and y coordinates are values between -300 and 300. </i> 
  
  <i> First image shows a **5** vertices star with a depth of 60%. </i>  
  ![generate_star](https://user-images.githubusercontent.com/68897925/155890134-be02b4e5-90ff-4183-9aac-3e89c3dd9cb4.png)
    <br><br><br><br>
  <i> Second image shows a **16** vertices start with a depth of 90%. </i>
    <br>
  ![generate_star2](https://user-images.githubusercontent.com/68897925/155890138-a60a5904-c8e7-4f78-991f-e2657314c2c3.png)  
  
  <i>For simplicity reason the explanation will continue with the first example. The algorith of star generation is the next one:   
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
    angle=k*36;  where k <span>&#8712;</span> [0,360)<br>      
    ...<br>     
    324=9*36;<br>     
</i>
<p>
  <i>
    If <b>k</b> is even number the point from the polygonal contour will be a main vertex with polar coordinates <b>(long radius,angle)</b>.  
    If <b>k</b> is odd number the point from the polygonal contour will be a secondary vertex with polar coordinates <b>(short radius,angle)</b>.
  </i>
</p>
<i>
  The star will be represented by the polygonal contour that joins all these points ordered by polar coordinate <b>angle</b>. Must be specified that the points added to the contour are given in cartesian coordinates. A previous conversion is necessary.   
</i>
