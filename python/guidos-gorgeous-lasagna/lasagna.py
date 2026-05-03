EXPECTED_BAKE_TIME = 40
PREPARATION_TIME = 2


def bake_time_remaining(elapsed_bake_time):
    """Calculate the remaining bake time.

    Args:
        elapsed_bake_time (int): The number of minutes the lasagna has already
            been baking in the oven.

    Returns:
        int: The number of minutes still left to bake.
    """
    return EXPECTED_BAKE_TIME - elapsed_bake_time


def preparation_time_in_minutes(number_of_layers):
    """Calculate the preparation time.

    Args:
        number_of_layers (int): The number of layers in the lasagna.

    Returns:
        int: Total preparation time in minutes (2 minutes per layer).
    """
    return number_of_layers * PREPARATION_TIME


def elapsed_time_in_minutes(number_of_layers, elapsed_bake_time):
    """Calculate the total elapsed time since starting to prepare the lasagna.

    Total time = preparation time + time already spent baking.

    Args:
        number_of_layers (int): The number of layers in the lasagna.
        elapsed_bake_time (int): The number of minutes the lasagna has already
            been baking.

    Returns:
        int: Total elapsed time in minutes.
    """
    return preparation_time_in_minutes(number_of_layers) + elapsed_bake_time
