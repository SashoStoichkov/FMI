class Booking {
  constructor(id, firstName, lastName, eventId) {
    this.id = id;
    this.name = firstName + " " + lastName;
    this.eventId = eventId;
  }

  getId() {
    return this.id;
  }

  getName() {
    return this.name;
  }

  getEventId() {
    return this.eventId;
  }
}

module.exports = Booking;
