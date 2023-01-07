def hex_to_imgui_rgba(hex_code: str) -> tuple:
    # Parse the hex code and normalize it to 6 digits
    hex_code = hex_code.lstrip('#')
    if len(hex_code) == 3:
        hex_code = hex_code[0] + hex_code[0] + hex_code[1] + hex_code[1] + hex_code[2] + hex_code[2]
    elif len(hex_code) != 6:
        raise ValueError(f"Invalid hex code: {hex_code}")

    # Convert the hex code to RGB values
    r = int(hex_code[0:2], 16) / 255
    g = int(hex_code[2:4], 16) / 255
    b = int(hex_code[4:6], 16) / 255

    # Return the RGBA tuple
    return (r, g, b, 1.0)

# Example usage:
rgba = hex_to_imgui_rgba('#0249f9')
print(rgba)