const Event = require("./event.js");
const Booking = require("./booking.js");

let EVENT_ID = 1;
let BOOKING_ID = 1;

let events = [];
let bookings = [];

const express = require("express");
const app = express();
app.use(express.json());

const PORT = 8080;

// get /event - returns all events
app.get("/event", (req, res) => {
  res.json(events);
});

// post /event - create a new event
// body: { name: "string", capacity: "number" }
// response: { event }
app.post("/event", (req, res) => {
  const event = new Event(EVENT_ID, req.body.name, req.body.capacity);
  EVENT_ID++;

  events.push(event);
  res.json(event);
});

function getEventById(id) {
  return events.find((event) => event.getId() === id) || null;
}

// get /event/:id - get an event by id
// response: { event }
app.get("/event/:id", (req, res) => {
  const event = getEventById(+req.params.id);
  if (!event) {
    res.status(404).send("Event not found");
    return;
  }

  res.json(event);
});

// delete /event/:id - delete an event by id
// response: { event }
app.delete("/event/:id", (req, res) => {
  const event = getEventById(+req.params.id);
  if (!event) {
    res.status(404).send("Event not found");
    return;
  }

  events = events.filter((e) => e.getId() !== event.getId());
  res.json(event);
});

// post /event/:id/booking - create a new booking for an event if there is capacity
// body: { firstName: "string", lastName: "string" }
// response: { remainingCapacity }
app.post("/event/:id/booking", (req, res) => {
  const event = getEventById(+req.params.id);
  if (!event) {
    res.status(404).send("Event not found");
    return;
  }

  if (event.getRemainingCapacity() > 0) {
    const booking = new Booking(
      BOOKING_ID,
      req.body.firstName,
      req.body.lastName,
      event.getId()
    );
    BOOKING_ID++;

    bookings.push(booking);
    event.remainingCapacity--;
    res.json(event.remainingCapacity);
  } else {
    res.status(400).json({ error: "Event is full" });
  }
});

// get /event/:id/booking - get all bookings for an event
// response: { bookings }
app.get("/event/:id/booking", (req, res) => {
  const event = getEventById(+req.params.id);
  if (!event) {
    res.status(404).send("Event not found");
    return;
  }

  const eventBookings = bookings.filter(
    (booking) => booking.getEventId() === event.getId()
  );
  res.json(eventBookings);
});

// get /event/:id/booking/:bookingId - get a booking by id
// response: { booking }
app.get("/event/:id/booking/:bookingId", (req, res) => {
  const event = getEventById(+req.params.id);
  if (!event) {
    res.status(404).send("Event not found");
    return;
  }

  const booking =
    bookings.find((booking) => booking.getId() === +req.params.bookingId) ||
    null;
  if (!booking) {
    res.status(404).send("Booking not found");
    return;
  }

  res.json(booking);
});

// delete /event/:id/booking/:bookingId - delete a booking by id
// response: { booking }
app.delete("/event/:id/booking/:bookingId", (req, res) => {
  const event = getEventById(+req.params.id);
  if (!event) {
    res.status(404).send("Event not found");
    return;
  }

  const booking =
    bookings.find((booking) => booking.getId() === +req.params.bookingId) ||
    null;

  if (!booking) {
    res.status(404).send("Booking not found");
    return;
  }

  bookings = bookings.filter((b) => b.getId() !== booking.getId());
  event.remainingCapacity++;
  res.json(booking);
});

app.listen(PORT, () => {
  console.log(`Server started on port ${PORT}`);
});
