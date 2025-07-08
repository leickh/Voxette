const std = @import("std");
const Voxette3D = @import("Voxette3D");

pub fn main() !void {
    try Voxette3D.Renderer.init();
}
