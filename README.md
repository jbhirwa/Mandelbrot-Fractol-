To select a fractal, type the fractol name after the program name.

Example: ./fractol "mandelbrot"

	1	mandelbrot
	
	2	julia fixed
	
	3	julia explore
	
	4	burning ship
	
Make sure your selection is enclosed in double quotes

In-program commands

	1	To change the fractal you can press the number
		corresponding to it.
		
	2	In "julia explore" using the arrows changes
		the real imaginery part pf the constant.
		
	3	To reset, press the corresponding number.



https://rosettacode.org/wiki/Mandelbrot_set
https://en.wikipedia.org/wiki/Julia_set

# What is the Mandelbrot set?
The Mandelbrot set is created with the following function <img src="https://render.githubusercontent.com/render/math?math=f(z)%20=%20z^{2}%20%2B%20c">, here c and z are complex numbers. C represents the current point on the complex plane that we want to know whether or not it is In the Mandelbrot Set. For C to be within The Mandelbrot Set it needs to remain stable within a max number of iterations, after which that point will be colored black. Stability is determined by assessing whether or not the current z value when squared and then square rooted is not greater than 2, if so, usually you would stop iterating the function. Points that don’t iterate to the max iteration are given a color according to how fast they stopped iterating, resulting in the patterns and colorfulness of fractals. Most complex numbers within the Mandelbrot set stabilise within 50 iterations, as shown with figure two. For further information please watch the videos from the links found at the bottom of this document.

![image](https://user-images.githubusercontent.com/59305365/142963905-761bfc1b-c9a4-48fd-8ffb-002634605302.png)

*(figure one)*

![image](https://user-images.githubusercontent.com/59305365/142961100-4bf9846a-03af-4509-9369-d29368cf5f78.png)

*(figure two)*

# Understanding the 42 MLX library
It is be best to start off with the first link as it does a decent job of introducing the main functions of the mlx library, as well as, walk you through some very simple programs. The second link is a big link dump repository of resources to almost any problem you might face, it also has the man for most of the functions. The last two are mini projects walkthroughs, they were extremely helpful once you have a decent understanding of the mlx functions.

# Implementing fractals 
Wikipedia as well as YouTube have resources or pseudocode you can use to help develop your code. I found that once I implemented The Mandelbrot Set, I only had to make small changes to make the Julia set and burning ship fractal, these changes are explained in their respective wikipedia articles. 


### Helpful Links

### Mandelbrot Explanation
https://www.youtube.com/watch?v=FFftmWSzgmk

https://www.youtube.com/watch?v=7MotVcGvFMg

https://www.youtube.com/watch?v=7MotVcGvFMg&list=TLPQMjIxMTIwMjFdXkOetTn_rA&index=1

https://www.youtube.com/watch?v=6IWXkV82oyY

### Mini Documentary
https://www.youtube.com/watch?v=56gzV0od6DU

### Interactive Mandelbrot set, this is also the desired outcome of this project.
https://www.google.com/fbx?fbx=mandelbrot_explorer&hl=en



### Implementing fractals 
https://rosettacode.org/wiki/Mandelbrot_set

https://en.wikipedia.org/wiki/Julia_set

https://www.youtube.com/watch?v=mBg74yR3ZiY&t=1180s

https://www.youtube.com/watch?v=6z7GQewK-Ks&t=612s

https://en.wikipedia.org/wiki/Mandelbrot_set

https://en.wikipedia.org/wiki/Burning_Ship_fractal

https://jonisalonen.com/2013/lets-draw-the-mandelbrot-set/



### Understanding the mlx library
https://harm-smits.github.io/42docs/libs/minilibx/colors.html

https://github.com/qst0/ft_libgfx#the-graphics-branch

### mlx ##mini projects 
https://giters.com/S-LucasSerrano/miniLibX_sample

https://giters.com/keuhdall/images_example
