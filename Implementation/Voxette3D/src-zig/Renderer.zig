const std = @import("std");
const sdl3 = @import("sdl3");
const zgl = @import("zgl");

pub fn init() !void {
    try sdl3.init(
        .{ .video = true, .events = true, .audio = true },
    );

    var window = try sdl3.video.Window.init(
        "Unnamed Application | Voxette",
        1280,
        720,
        .{
            .hidden = false,
            .open_gl = true,
            .resizable = true,
        },
    );
    defer window.deinit();

    const surface = try window.getSurface();
    try surface.fillRect(
        .{ .x = 0, .y = 0, .w = 1280, .h = 720 },
        .{ .value = 0xff000000 },
    );
    try window.updateSurface();

    try window.show();

    var running = true;
    while (running) {
        const nullable_event = sdl3.events.poll();
        if (nullable_event != null) {
            switch (nullable_event.?) {
                .quit, .terminating => {
                    running = false;
                    try window.hide();
                },
                else => {},
            }
        }
        std.time.sleep(1024 * 1024 * 10); // Wait 10 milliseconds
    }
}
