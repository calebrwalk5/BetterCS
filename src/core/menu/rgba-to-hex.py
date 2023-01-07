import imgui

def rgba_to_hex(rgba: imgui.Vec4) -> str:
    return '#{:02x}{:02x}{:02x}{:02x}'.format(int(rgba.x * 255), int(rgba.y * 255), int(rgba.z * 255), int(rgba.w * 255))

if __name__ == '__main__':
    rgba = imgui.Vec4(0.03, 0.23, 0.04, 0.62)
    hex_string = rgba_to_hex(rgba)
    print(hex_string)
