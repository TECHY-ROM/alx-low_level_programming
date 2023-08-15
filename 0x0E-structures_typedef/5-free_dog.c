#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Free dogs
 * @d: the dog to free
 */

void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->owner);
	free(d->name);
	free(d);
}
