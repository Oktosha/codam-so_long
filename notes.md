# Notes

looks like coordinates outside window are allowed (negative & big)

hooks don't have to be thread-safe, they are always called from the main thread

mlx_close_window is safe to call from a hook (and mlx_terminate -> not)