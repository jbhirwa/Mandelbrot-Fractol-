#include "fractol.h"
void		t_fractol(t_brain *brain)
{
	t_brain		brain_tab[THREADS];
	pthread_t	threads[THREADS];
	int			i;
	int			thread_width;

	i = 0;
	thread_width = WIDTH / THREADS;
	while (i < THREADS)
	{
		brain_tab[i] = *brain;
		//ft_memcpy((void*)&brain_tab[i], (void *)brain, sizeof(brain));
		brain_tab[i].t.start = thread_width * i;
		brain_tab[i].t.end = thread_width * (i + 1);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_create(&threads[i], NULL, (void *)fractol, &brain_tab[i]);//something
		i += 1;
	}
	while (i--)
	{
		pthread_join(threads[i], NULL);
		mlx_put_image_to_window(brain->d.mlx, brain->d.win, brain->d.img, 0, 0);//
	}
}

