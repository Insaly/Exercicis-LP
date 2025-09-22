import numpy as np

def find_val(mat, value):
    positions = np.where(mat == value)
    return list(zip(positions[0], positions[1]))

def approx_color_to_grayscale(mat, scale_factor=None):
    if scale_factor is None:
        return mat.mean(axis=2)
    else:
        return (mat * scale_factor).sum(axis=2)
