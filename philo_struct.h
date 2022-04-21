

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

typedef struct s_ph
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_eats;

}	t_ph;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
	t_philo			*next_philo;
	t_philo			*last_philo;
}	t_philo;

#endif